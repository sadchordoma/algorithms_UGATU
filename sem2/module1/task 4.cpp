/**
1)Дано N кубиков. Требуется определить каким количеством способов можно выстроить 
из этих кубиков пирамиду. Каждый вышележащий слой пирамиды должен быть не больше нижележащего.
2)65843065
3)https://contest.yandex.ru/contest/35212/problems/4_2/
**/

#include <iostream>

#include <vector>

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    vector<vector<long long>> dp(n);
    if (n == 1 || n == 2 || n == 0) {
        cout << n;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        dp[i].resize(n, 0);
    }
    for (int i = 0; i < n; i++) {
        dp[i][0] = 1;
        dp[0][i] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (i == j) {
                dp[i][j] = dp[i][j - 1] + 1; 
            }
            else if (i > j) {
                dp[i][j] = dp[i - j - 1][j] + dp[i][j - 1];

            }
            else {
                dp[i][j] = dp[i][j - 1];

            }
        }
    }
    cout << dp[n - 1][n - 1];
    return 0;
}
