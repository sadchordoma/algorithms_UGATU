/**
1)В некотором государстве в обращении находятся банкноты определенных номиналов. 
Национальный банк хочет, чтобы банкомат выдавал любую запрошенную сумму при помощи 
минимального числа банкнот, считая, что запас банкнот каждого номинала неограничен. 
Помогите Национальному банку решить эту задачу.
2)65810441
3)https://contest.yandex.ru/contest/35212/problems/3_2/
**/
#include <iostream>

#include <algorithm>

#include <vector>

using namespace std;

void print(vector<int> va) {
    for (auto el: va) {
        cout << el << " ";
    }
    cout << "\n";
}


vector<int> input_data(int n, vector<int> greenbacks) {
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        greenbacks.push_back(m);
    }
    return greenbacks;
}
int main() {
    int n;
    vector<int> greenbacks;
    cin >> n;
    greenbacks = input_data(n, greenbacks);
    int sum = 0;
    cin >> sum;
    sort(greenbacks.begin(), greenbacks.end());
    vector<vector<int>> dp(sum + 1);
    int start = greenbacks[0];
    bool flag = false;
    for (int el: greenbacks) {
        if (el == sum) {
            flag = true;
            cout << 1 << "\n" << el;
            break;
        }
        else if (sum < el) {
            continue;
        }
        dp[el].push_back(el);
    }

    if (!flag) {
        for (int i = start + 1; i < sum + 1; i++) {
            int new_start = 0;
            if (dp[i].empty()) {
                for (int j = 0; j < greenbacks.size(); j++) {
                    if (i - greenbacks[j] > 0) {
                        if (!dp[i - greenbacks[j]].empty() && !dp[greenbacks[j]].empty()) {
                            for (auto el: dp[greenbacks[j]]) {
                                dp[i].push_back(el);
                            }
                            for (auto el: dp[i - greenbacks[j]]) {
                                dp[i].push_back(el);
                            }
                            new_start = j + 1;
                            break;
                        }
                    }
                }
                for (int k = new_start; k < greenbacks.size(); k++) {
                    if (greenbacks[k] > i || i - greenbacks[k] < 0) {
                        break;
                    }
                    if (!dp[i - greenbacks[k]].empty() &&
                        dp[i].size() > dp[greenbacks[k]].size() + dp[i - greenbacks[k]].size()) {
                        dp[i].clear();
                        for (auto el: dp[greenbacks[k]]) {
                            dp[i].push_back(el);
                        }
                        for (auto el: dp[i - greenbacks[k]]) {
                            dp[i].push_back(el);
                        }
                    }
                }
            }
        }
    }
    if (!flag) {
        if (!dp[sum].empty()) {
            sort(dp[sum].begin(), dp[sum].end(), [] (int a, int b) {return a > b;});
            cout << dp[sum].size() << "\n";
            print(dp[sum]);
        }
        else {
            cout << -1;
        }
    }
    return 0;
}
