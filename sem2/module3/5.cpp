/**
1)Дана строка длины n. Найти количество ее различных подстрок. Используйте суффиксный массив.
Построение суффиксного массива выполняйте за O(n log n). Вычисление количества различных подстрок выполняйте за O(n)
2)68812722
3)https://contest.yandex.ru/contest/37787/problems/5/
**/
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
const int N = 2e5;

int order[N], now_suff_add, n;

int get_order(int pos) {
    if (pos < n) {
        return order[pos];
    }
    return -1;
}

bool comp(pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first) {
        return a.first < b.first;
    }
    return get_order(a.second + now_suff_add) < get_order(b.second + now_suff_add);
}

void solve(string s) {
    n = s.length();
    int cnt[26];
    for (int i = 0; i < 26; i++) {
        cnt[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        cnt[s[i] - 'a']++;
    }
    for (int i = 1; i < 26; i++) {
        cnt[i] += cnt[i - 1];
    }
    vector<pair<int, int> > suf;
    for (int i = 0; i < n; i++) {
        order[i] = cnt[s[i] - 'a'] - 1;
        suf.push_back({order[i], i});
    }
    sort(suf.begin(), suf.end(), comp);
    now_suff_add = 1;
    while (now_suff_add <= n) {
        sort(suf.begin(), suf.end(), comp);
        for (int i = suf.size() - 2; i >= 0; i--) {
            if (get_order(suf[i].second + now_suff_add) < get_order(suf[i + 1].second + now_suff_add)) {
                suf[i].first = i;
            }
            else {
                suf[i].first = min(suf[i + 1].first, suf[i].first);
            }
        }
        for (auto [order_suf, suf_num] : suf) {
            order[suf_num] = order_suf;
        }
        now_suff_add += now_suff_add;
    }
    vector<int> LCP(n);
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        pos[suf[i].second] = i;
    }
    int current_LCP = 0;
    for (int i = 0; i < n; i++) {
        if (pos[i] == n - 1) {
            current_LCP = 0;
            continue;
        }
        int q = suf[pos[i] + 1].second;
        current_LCP--;
        if (current_LCP < 0) {
            current_LCP = 0;
        }
        while(i + current_LCP < n && q + current_LCP < n && s[i + current_LCP] == s[q + current_LCP]) {
            current_LCP++;
        }
        LCP[pos[i]] = current_LCP;
    }
    size_t answer = 0;
    for (int i = 0; i < n; i++) {
        answer += n - suf[i].second - LCP[i];
    }
    cout << answer;
}

int main() {
    string s;
    cin >> s;
    solve(s);
    return 0;
}
