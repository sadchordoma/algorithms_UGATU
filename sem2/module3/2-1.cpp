/**
1)Найти лексикографически-минимальную строку, построенную по префикс-функции, в алфавите a-z.
2)68619722
3)https://contest.yandex.ru/contest/37787/problems/2_1/
**/
#include <vector>
#include <string>
#include <iostream>

using namespace std;

string build_str_by_pi(vector<size_t> pi) {
    if (pi.empty()) {
        return "";
    }
    string s = "a";
    
    for (size_t i = 1; i < pi.size(); i++) {
        if (pi[i] != 0) {
            s += s[pi[i] - 1];
        } 
        else {
            vector<bool> used(26, false);
            size_t k = pi[i - 1];
            while (k > 0) {
                used[result[k] - 'a'] = true;
                k = pi[k - 1];
            }
            char c = 'b';
            while (used[c - 'a']) {
                c++;
            };
            s += c;
        }
    }
    return s;
}

int main() {
    size_t x;
    vector<size_t> pi;
    while (cin >> x) {
        pi.push_back(x);
    }
    cout << build_str_by_pi(pi);
    return 0;
}
