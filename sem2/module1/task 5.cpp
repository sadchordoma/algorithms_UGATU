/**
1)Дано невзвешенное дерево. Расстоянием между двумя вершинами будем называть количество ребер в пути,
соединяющем эти две вершины. Для каждой вершины определите сумму расстояний до всех остальных вершин. 
Время работы должно быть O(n).
2)	66105644
3)https://contest.yandex.ru/contest/35212/problems/5_2/
**/
#include <iostream>

#include <vector>

using namespace std;

struct TreeNode {
public:
    int parent = 0;
    vector<int> children;
    int res = 0;
    int count_vertices_in_subtree = 1;
};

int DFS(int start, std::vector<int> &order, std::vector<int> &visited, vector<TreeNode>& dp) {
    int sum_do_ost = 0;
    if (!visited[start]) {
        order.push_back(start);
        visited[start] = true;
        for (auto to: dp[start].children) {
            sum_do_ost += DFS(to, order, visited, dp) + dp[to].count_vertices_in_subtree;
            dp[start].count_vertices_in_subtree += dp[to].count_vertices_in_subtree;
        }
    }
    return sum_do_ost;
}

int main() {
    int n;
    cin >> n;
    vector<TreeNode> dp(n);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b) {
            swap(a, b);
        }
        dp[a].children.push_back(b);
        dp[b].parent = a;
    }
    vector<int> order;
    vector<int> visited(n);
    int dp_one = DFS(0, order, visited, dp);
    dp[0].res = dp_one;
    cout << dp_one << "\n";
    for (int i = 1; i < dp.size(); i++) {
        dp[i].res = dp[dp[i].parent].res + n - 2 * dp[i].count_vertices_in_subtree;
        cout << dp[i].res << "\n";
    }
    return 0;
}
