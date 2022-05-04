/**
1)Дан ориентированный граф. Определите, какое минимальное число ребер необходимо добавить, 
чтобы граф стал сильносвязным. 
В графе возможны петли.
2)68087958
3)https://contest.yandex.ru/contest/36361/problems/3/
**/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 10000;
vector<int> g[N], gr[N];
vector<int> top_sort;
bool visited[N], marked[N];
int belong_to_component[N];
int component_id = 0;

void topological_sort(int u) {
    visited[u] = true;
    for (auto to : g[u]) {
        if (!visited[to]) {
            topological_sort(to);
        }
    }
    top_sort.push_back(u);
}

vector<int> component;

void dfs(int u) {
    component.push_back(u);
    belong_to_component[u] = component_id;
    marked[u] = 1;
    for (auto to : gr[u]) {
        if (!marked[to]) {
            dfs(to);

        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (a == b) {
            continue;
        }
        a--;
        b--;
        g[a].push_back(b);
        gr[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]){
            topological_sort(i);
        }
    }
    reverse(top_sort.begin(), top_sort.end());
    for (auto i : top_sort) {
        if (!marked[i]) {
            dfs(i);
            component.clear();
            component_id++;
        }
    }
    vector<pair<bool, bool>> v(component_id);
    for (int i = 0; i < n; i++) {
        for (auto ver : g[i]) {
            if (belong_to_component[i] != belong_to_component[ver]) {
                v[belong_to_component[i]].first = true;
                v[belong_to_component[ver]].second = true;
            }
        }
    }
    int k1 = 0;
    int k2 = 0;
    if (v.size() > 1) {
        for (auto item : v) {
            if (!item.first) {
                k1++;
            }
            if (!item.second) {
                k2++;
            }
        }
    }
    cout << max(k1, k2);
    return 0;
}
