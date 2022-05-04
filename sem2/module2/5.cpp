/**
1)Тесты пока не готовы!
Необходимо написать торгового советника для поиска арбитража.
Арбитраж - это торговля по цепочке различных валют в надежде заработать на небольших различиях в коэффициентах. Например, есть следующие курсы валют:
GBP/USD: 0.67
RUB/GBP: 78.66
USD/RUB: 0.02
Имея 1$ и совершив цикл USD->GBP->RUB->USD, получим 1.054$. Таким образом заработав 5.4
2)68087661
3)https://contest.yandex.ru/contest/36361/problems/5/
**/

#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int from, to;
    float cost;
};

bool Belman_Ford(int n, vector<Edge>& edges) {
    vector<float>dp(n, 0);
    dp[0] = 100;
    int steps = n - 1;
    while (steps--) {
        bool something_changed = false;
        for (auto ed : edges) {
            if (dp[ed.to] < dp[ed.from] * ed.cost) {
                dp[ed.to] = dp[ed.from] * ed.cost;
                something_changed = true;
            }
        }
        if (!something_changed) {
            break;
        }
    }
    for (auto ed : edges) {
        if (dp[ed.to] < dp[ed.from] * ed.cost) {
            dp[ed.to] = dp[ed.from] * ed.cost;
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<Edge> edges;
    for (int i = 0; i < n; i++) {
        float x;
        for (int j = 0; j < n; j++) {
            if (j == i) {
                continue;
            }
            cin >> x;
            if (x == -1) {
                continue;
            }
            else {
                edges.push_back({i, j, x});
            }
        }
    }
    if (Belman_Ford(n, edges)) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}
