/**
1)Требуется отыскать самый короткий маршрут между городами.
Из города может выходить дорога, которая возвращается в этот же город.
Требуемое время работы O((N + M)log N), где N – количество городов, M – известных дорог между ними.
N ≤ 10000, M ≤ 250000.
Длина каждой дороги ≤ 10000.
2)67763718
3)https://contest.yandex.ru/contest/36361/problems/4/
**/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void Djkstra(int start, int N, vector<vector<pair<int, int>>> g, vector<int> &distance) {
    priority_queue<pair<int, int>> Q;
    // 1 - dist, 2 - elem
    Q.push({0, start});
    distance[start] = 0;
    while (!Q.empty()) {
        auto [dist, elem] = Q.top();
        Q.pop();
        dist = -dist;
        for (auto [el, new_dist]: g[elem]) {
            if (dist + new_dist < distance[el]) {
                distance[el] = dist + new_dist;
                Q.push({-distance[el], el});
            }
        }
    }
}
int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<pair<int, int>>> graph(N);
    vector<int> distance(N, 1e9);
    for (int i = 0; i < M; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back({to, cost});
        graph[to].push_back({from, cost});
    }
    int from_find, to_find;
    cin >> from_find >> to_find;
    Djkstra(from_find, N, graph, distance);
    cout << distance[to_find];
    return 0;
}
