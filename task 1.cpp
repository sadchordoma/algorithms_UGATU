/**
1)https://contest.yandex.ru/contest/32613/problems/1_3/
2)60926143
3)Дано число N ≤ 104 и последовательность целых чисел из [-231..231] длиной N. 
Требуется построить бинарное дерево, заданное наивным порядком вставки. Т.е., 
при добавлении очередного числа K в дерево с корнем root, если root→Key ≤ K, 
то узел K добавляется в правое поддерево root; иначе в левое поддерево root. 
Выведите элементы в порядке post-order (снизу вверх).
Рекурсия запрещена.
**/
#include <bits/stdc++.h>

#include <algorithm>

using namespace std;

class Node {
private:
    int key;
    Node *left;
    Node *right;
    Node *parent;
public:
    Node() {}

    Node(int given_key) : key(given_key), left(nullptr), right(nullptr), parent(nullptr) {}

    int get_key() const {
        return key;
    }

    Node *get_left() {
        return left;
    };

    Node *get_right() {
        return right;
    }

    void MakeLeftSon(int new_key, Node *PARENT) {
        left = new Node(new_key);
        left->parent = PARENT;
    }

    void MakeRightSon(int new_key, Node *PARENT) {
        right = new Node(new_key);
        right->parent = PARENT;
    }
    Node *Parent() {
        return parent;
    }

};

Node *root;

void insert(Node *curRoot, int new_key) {
    Node *curprev;
    bool left;
    while (curRoot != nullptr) {
        if (new_key <= curRoot->get_key()) {
            curprev = curRoot;
            curRoot = curRoot->get_left();
            left = true;
        } else {
            curprev = curRoot;
            curRoot = curRoot->get_right();
            left = false;
        }
    }
    if (left) {
        curprev->MakeLeftSon(new_key, curprev);
    } else {
        curprev->MakeRightSon(new_key, curprev);
    }
}

void postorderPrint(Node *curRoot) {
    stack<Node *> stack_of_vertexs;
    vector<int> numbers;
    numbers.push_back(curRoot->get_key());
    auto left_branch = curRoot->get_left();
    auto right_branch = curRoot->get_right();
    stack_of_vertexs.push(right_branch);
    while (stack_of_vertexs.empty() != 1) {
        auto stack_top = stack_of_vertexs.top();
        numbers.push_back(stack_top->get_key());
        stack_of_vertexs.pop();
        if (stack_top->get_left()) {
            stack_of_vertexs.push(stack_top->get_left());
        }
        if (stack_top->get_right()) {
            stack_of_vertexs.push(stack_top->get_right());
        }
    }
    stack_of_vertexs.push(left_branch);
    while (stack_of_vertexs.empty() != 1) {
        auto stack_top = stack_of_vertexs.top();
        numbers.push_back(stack_top->get_key());
        stack_of_vertexs.pop();
        if (stack_top->get_left()) {
            stack_of_vertexs.push(stack_top->get_left());
        }
        if (stack_top->get_right()) {
            stack_of_vertexs.push(stack_top->get_right());
        }
    }
    reverse_copy(numbers.begin(), numbers.end(), ostream_iterator<int>( std::cout, " " ));
}

int main() {
    int n;
    cin >> n;
    int elem;
    cin >> elem;
    root = new Node(elem);
    for (int i = 1; i < n; i++) {
        cin >> elem;
        insert(root, elem);
    }
    postorderPrint(root);
    return 0;
}
