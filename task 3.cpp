/**
1)https://contest.yandex.ru/contest/32613/problems/3_2/
2)62863033
3)Дано число N и N строк. Каждая строка содержащит команду добавления или удаления натуральных чисел, 
а также запрос на получение k-ой порядковой статистики. Команда добавления числа A задается положительным 
числом A, команда удаления числа A задается отрицательным числом “-A”. Запрос на получение k-ой порядковой 
статистики задается числом k. Требуемая скорость выполнения запроса - O(log n).
**/
#include <iostream>

#include <vector>

using namespace std;

struct node // структура для представления узлов дерева
{
    int key;
    int size;
    unsigned char height;
    node *left;
    node *right;

    node(int k) {
        key = k;
        left = right = 0;
        height = 1;
        size = 1;
    }
};

int sz(node *vertex) {
    if (vertex) {
        return vertex->size;
    }
    else {
        return 0;
    }
}

void update(node *vertex) {
    vertex->size = sz(vertex->left) + sz(vertex->right) + 1;
}
////////////////////////////////////////////////
unsigned char height(node *p) {
    if (p) {
        return p->height;
    } else {
        return 0;
    }
}

int bfactor(node *p) {
    return height(p->right) - height(p->left);
}

void fixheight(node *p) {
    unsigned char hl = height(p->left);
    unsigned char hr = height(p->right);
    if (hl > hr) {
        p->height = hl + 1;
    } else {
        p->height = hr + 1;
    }
}

node *rotateright(node *p) // правый поворот вокруг p
{
    node *q = p->left;
    p->left = q->right;
    q->right = p;
    fixheight(q);
    fixheight(p);
    return q;
}

node *rotateleft(node *q) // левый поворот вокруг q
{
    node *p = q->right;
    q->right = p->left;
    p->left = q;
    fixheight(p);
    fixheight(q);
    return p;
}

node *balance(node *p) // балансировка узла p
{
    fixheight(p);
    if (bfactor(p) == 2) {
        if (bfactor(p->right) < 0) {
            p->right = rotateright(p->right);
        }
        return rotateleft(p);
    }
    if (bfactor(p) == -2) {
        if (bfactor(p->left) > 0) {
            p->left = rotateleft(p->left);
        }
        return rotateright(p);
    }
    return p; // балансировка не нужна
}

node *insert(node *p, int k) // вставка ключа k в дерево с корнем p
{
    if (!p) return new node(k);
    if (k < p->key) {
        p->left = insert(p->left, k);
    }
    else {
        p->right = insert(p->right, k);
    }
    return balance(p);
}

node *findmin(node *p) // поиск узла с минимальным ключом в дереве p
{
    if (p->left) {
        return findmin(p->left);
    }
    return p;
}

node *removemin(node *p) // удаление узла с минимальным ключом из дерева p
{
    if (p->left == 0)
        return p->right;
    p->left = removemin(p->left);
    return balance(p);
}

node *remove(node *p, int k) // удаление ключа k из дерева p
{
    if (!p) return nullptr;
    if (k < p->key) {
        p->left = remove(p->left, k);
    }
    else if (k > p->key) {
        p->right = remove(p->right, k);
    }
    else //  k == p->key
    {
        node *q = p->left;
        node *r = p->right;
        delete p;
        if (!r) return q;
        node *min = findmin(r);
        min->right = removemin(r);
        min->left = q;
        return balance(min);
    }
    return balance(p);
}

void update_all(node *curRoot) {
    if (curRoot->left != nullptr) {
        update_all(curRoot->left);
    }
    if (curRoot->right != nullptr) {
        update_all(curRoot->right);
    }
    update(curRoot);
}

void print(node *curRoot) {
    if (curRoot->left != nullptr) {
        print(curRoot->left);
    }
    cout << curRoot->key << " " << sz(curRoot) << "\n";
    if (curRoot->right != nullptr) {
        print(curRoot->right);
    }
}

int find_kth_stat(node *root, int index) {
    if (sz(root->left) > index) {
        return find_kth_stat(root->left, index);
    }
    else if (sz(root->left) == index) {
        return root->key;
    }
    else {
        return find_kth_stat(root->right, index - sz(root->left) - 1);
    }
}

int main() {
    int n;
    int a, k;
    cin >> n;
    cin >> a >> k;
    node *root = new node(a);
    vector<int> kstat_mas;
    kstat_mas.push_back(find_kth_stat(root, k));
    for (int i = 1; i < n; i++) {
        cin >> a >> k;
        if (a > 0) {
            root = insert(root, a);
        }
        else {
            root = remove(root, abs(a));
        }
        update_all(root);
        kstat_mas.push_back(find_kth_stat(root, k));
    }
    for (auto to: kstat_mas) {
        cout << to << " ";
    }
    return 0;
}
