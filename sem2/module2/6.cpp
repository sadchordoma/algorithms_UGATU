/**
1)Найти в связном графе остовное дерево минимального веса.
2)67430320
3)https://contest.yandex.ru/contest/36361/problems/6/
**/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int N = 1000;
vector<pair<int, int>> graph(N);
int Prim(int V) {
    vector<int> dist(N, 1e9);
    vector<int> par(N, 0);
    vector<int> was(N, 0);
    dist[0] = 0;
    set<pair<int, int> > S;
    S.insert({0, 0});
    int cost_mst = 0;
    while (!S.empty()) {
        auto [distance, v] = *S.begin();
        cost_mst += distance;
        S.erase(S.begin());
        was[v] = 1;
        for (auto [u, cost] : graph[v]) {
            if (dist[u] > cost && was[u] == 0) {
                S.erase({dist[u], u});
                dist[u] = cost;
                par[u] = v;
                S.insert({dist[u], u});
            }
        }
    }
    return cost_mst;
}
int main() {
    int V = 0, E = 0;
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int from = 0, to = 0, cost = 0;
        cin >> from >> to >> cost;
        from--;
        to--;
        graph[from].push_back({to, cost});
        graph[to].push_back({from, cost});
    }
    cout << Prim(V);
    return 0;
}
