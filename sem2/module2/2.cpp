/**
1)Дан невзвешенный неориентированный граф. Найдите цикл минимальной длины.
2)67303594
3)https://contest.yandex.ru/contest/36361/problems/
**/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int find_cycle(int n, vector <vector<int>> &g) {
    int answer = 1e9;
    for (int i = 0; i < n; i++) {
        vector<int> distance(n, 1e9);
        vector<int> parent(n, -1);
        distance[i] = 0;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int u : g[v]) {
                if (distance[u] == 1e9) {
                    distance[u] = 1 + distance[v];
                    parent[u] = v;
                    q.push(u);
                }
                else if (parent[v] != u and parent[u] != v)
                    answer = min(answer, distance[v] + distance[u] + 1);
            }
        }
    }
    if (answer == 1e9) {
        return -1;
    }
    else {
        return answer;
    }
}
int main()
{
    int N, M;
    cin >> N >> M;
    vector <vector<int>> adj(N);
    vector <int> marked(N, 0);
    vector <int> cycle;
    for (int i = 0; i < M; i++) {
        int vertex1, vertex2;
        cin >> vertex1 >> vertex2;
        adj[vertex1].push_back(vertex2);
        adj[vertex2].push_back(vertex1);
    }
    int answer = find_cycle(N, adj);
    cout << answer;
    return 0;
}
