/**
1)https://contest.yandex.ru/contest/32613/problems/2_1/
2)60979479	
3)Дано число N < 106 и последовательность пар целых чисел из [-231, 231] длиной N.
Построить декартово дерево из N узлов, характеризующихся парами чисел (Xi, Yi). 
Каждая пара чисел (Xi, Yi) определяет ключ Xi и приоритет Yi в декартовом дереве.
Добавление узла в декартово дерево выполняйте следующим образом: 
При добавлении узла (x, y) выполняйте спуск по ключу до узла P с меньшим приоритетом. 
Затем разбейте найденное поддерево по ключу x так, чтобы в первом поддереве все ключи меньше x, 
а во втором больше или равны x. Получившиеся два дерева сделайте дочерними для нового узла (x, y). 
Новый узел вставьте на место узла P.
Построить также наивное дерево поиска по ключам Xi.
Т.е., при добавлении очередного числа K в наивное дерево с корнем root, 
если root→Key ≤ K, то узел K добавляется в правое поддерево root; иначе в левое поддерево root.
Вычислить разницу глубин наивного дерева поиска и декартового дерева. Разница может быть отрицательна, необходимо вывести модуль разности.
**/
#include <iostream>

using namespace std;

class Node {
public:
    int key, prior;
    int size = 1;
    int sum = 0;
    Node *left, *right;

    Node() {}

    Node(int key, int prior) : key(key), prior(prior), left(nullptr), right(nullptr), sum(key) {}
    
};

int sz(Node *vertex) {
    if (vertex) {
        return vertex->size;
    } else {
        return 0;
    }
}

int sum(Node *vertex) {
    if (vertex) {
        return vertex->sum;
    } else {
        return 0;
    }
}

void update(Node *vertex) {
    vertex->size = sz(vertex->left) + sz(vertex->right) + 1;
    vertex->sum = sum(vertex->left) + sum(vertex->right) + vertex->key;
}

void print(Node *curRoot) {
    if (curRoot->left != nullptr) {
        print(curRoot->left);
    }
    cout << curRoot->key << " " << curRoot->prior << "\n";
    if (curRoot->right != nullptr) {
        print(curRoot->right);
    }
}

pair<Node *, Node *> split(Node *curRoot, int x) {
    if (curRoot == nullptr) {
        return {nullptr, nullptr};
    }
    if (curRoot->key <= x) {
        auto splitted = split(curRoot->right, x);
        curRoot->right = splitted.first;
        update(curRoot);
        return {curRoot, splitted.second};
    } else {
        auto splitted = split(curRoot->left, x);
        curRoot->left = splitted.second;
        update(curRoot);
        return {splitted.first, curRoot};
    }
}

Node *merge(Node *root1, Node *root2) {
    if (root1 == nullptr) {
        return root2;
    }
    if (root2 == nullptr) {
        return root1;
    }
    if (root1->prior < root2->prior) {
        root2->left = merge(root1, root2->left);
        update(root2);
        return root2;
    } else {
        root1->right = merge(root1->right, root2);
        update(root1);
        return root1;
    }
}

bool find(Node *root, int x) {
    if (root == nullptr) {
        return false;
    }
    if (root->key == x) {
        return true;
    }
    if (root->key < x) {
        return find(root->right, x);
    } else {
        return find(root->left, x);
    }

}

Node *insert(Node *root, int x, int y) {
    Node *newx = new Node(x, y);
    auto splitted = split(root, x);
    auto res = merge(newx, splitted.second);
    return merge(splitted.first, res);
}

int find_kth_stat(Node *root, int x) {
    if (sz(root->left) > x) {
        return find_kth_stat(root->left, x);
    } else if (sz(root->left) == x) {
        return root->key;
    } else {
        return find_kth_stat(root->right, x - sz(root->left) - 1);
    }
}

int Count(Node *node) {
    if (node == nullptr)
        return 0;
    return Count(node->left) + Count(node->right) + 1;
}

int maxDepth(Node *temp) {
    if (temp == nullptr)
        return 0;

    else {
        int lchild = maxDepth(temp->left);
        int rchild = maxDepth(temp->right);

        if (lchild <= rchild)
            return rchild + 1;

        else
            return lchild + 1;

    }
}

Node *root;

class binaryNode {
private:
    int key;
    binaryNode *left;
    binaryNode *right;
    binaryNode *parent;
public:
    binaryNode() {}

    binaryNode(int given_key) : key(given_key), left(nullptr), right(nullptr), parent(nullptr) {}

    int get_key() const {
        return key;
    }

    binaryNode *get_left() {
        return left;
    };

    binaryNode *get_right() {
        return right;
    }

    void MakeLeftSon(int new_key, binaryNode *PARENT) {
        left = new binaryNode(new_key);
        left->parent = PARENT;
    }

    void MakeRightSon(int new_key, binaryNode *PARENT) {
        right = new binaryNode(new_key);
        right->parent = PARENT;
    }

    binaryNode *Parent() {
        return parent;
    }

    int maxDepth(binaryNode *temp) {
        if (temp == nullptr)
            return 0;

        else {
            int lchild = maxDepth(temp->left);
            int rchild = maxDepth(temp->right);

            if (lchild <= rchild)
                return rchild + 1;

            else
                return lchild + 1;

        }
    }
};

void insert(binaryNode *curRoot, int new_key) {
    binaryNode *curprev;
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

binaryNode *binaryroot;

int main() {
    int n;
    cin >> n;
    int a;
    int b;
    cin >> a;
    cin >> b;
    binaryroot = new binaryNode(a);
    root = insert(root, a, b);
    for (int i = 1; i < n; i++) {
        cin >> a;
        cin >> b;
        root = insert(root, a, b);
        insert(binaryroot, a);
    }
    cout << abs(maxDepth(root) - binaryroot->maxDepth(binaryroot));
    return 0;
}
