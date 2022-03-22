/**
1)Реализуйте структуру данных типа “множество строк” на основе динамической хеш-таблицы с открытой адресацией. Хранимые строки непустые и состоят из строчных латинских букв.
Хеш-функция строки должна быть реализована с помощью вычисления значения многочлена методом Горнера. Начальный размер таблицы должен быть равным 8-ми. Перехеширование выполняйте при добавлении элементов в случае, когда коэффициент заполнения таблицы достигает 3/4.
Структура данных должна поддерживать операции добавления строки в множество, удаления строки из множества и проверки принадлежности данной строки множеству.

Вариант 1. Для разрешения коллизий используйте квадратичное пробирование.
i-ая проба g(k, i)=g(k, i-1) + i (mod m). m - степень двойки.
Вариант 2. Для разрешения коллизий используйте двойное хеширование.
2)	65660036
3)  https://contest.yandex.ru/contest/35212/problems/
**/

#include <iostream>

#include <vector>

#include <string>

using namespace std;

class HashTable {
private:
    struct Node {
        string value;
        bool is_deleted;
        Node(string Value = "") {
            is_deleted = false;
            value = Value;
        }
    };

    float loadfactor = 0;
    int tablesize = 0;
    double added = 0;
    vector<Node> table;

    double Loadfactor() const {
        return added / tablesize;
    }

    int step(int i) {
        return i * i;
    }
    void resize() {
        vector<Node> elems;
        for (auto elem: table) {
            if (elem.value != "" && !elem.is_deleted) {
                elems.push_back(elem);
            }
        }
        table.clear();
        tablesize *= 2;
        table.resize(tablesize, {});
        added = 0;
        for (auto elem: elems) {
            insert(elem.value);
            added++;
        }
    }

    int h(string s, int m) {
        int hash = 0;
        int a = 31;
        for (char i : s) {
            hash = (hash * a + i) % m;
        }
        return hash;
    }
public:
    HashTable() {
    tablesize = 8;
    table.resize(tablesize);
    }
    ~HashTable() {
    table.clear();
    }
    bool insert(string s) {
        int i = 1;
        if (!has(s)) {
            int hash = h(s, tablesize);
            while (table[hash].value != "" && !table[hash].is_deleted) {
                hash += step(i);
                i++;
                hash %= tablesize;
            }

            table[hash] = s;
            added++;
            if (Loadfactor() > 0.7) {
                resize();
            }
            return true;
            // добавил
        }
        else {
            return false;
            // уже есть
        }
    }
    void print() {
        for (auto el: table) {
            cout << "value: " << el.value << " hash: " << h(el.value, tablesize) << "\n";
        }
    }
    bool has(string s) {
        int i = 1;
        int hash = h(s, tablesize);
        while (table[hash].value != "" && table[hash].value != s) {
            hash += step(i);
            i++;
            hash %= tablesize;
        }
        if (table[hash].value == s && !table[hash].is_deleted) {
            return true;
            // есть
        }
        return false;
        // нет
    }
    void print_() {
        for (int i = 0; i < tablesize; i++) {
            if (table[i].value != "") {
                cout << table[i].value << " " << i << "\n";
            }
        }
    }
    bool remove(string s) {
        int i = 1;
        int hash = h(s, tablesize);
        while ((table[hash].value != "" && table[hash].value != s) || table[hash].is_deleted) {
            hash += step(i);
            i++;
            hash %= tablesize;
        }
        if (table[hash].value == s && !table[hash].is_deleted) {
            table[hash].value = "";
            table[hash].is_deleted = true;
            added--;
            return true;
            // удалил
        }
        return false;
        // не было
    }
};



int main() {
    HashTable table;
    char command;
    string s;
    while (cin >> command >> s) {
        if (command == '?') {
            if (table.has(s)) {
                cout << "OK" << "\n";
            }
            else {
                cout << "FAIL" << "\n";
            }
        }
        if (command == '+') {
            if (table.insert(s)) {
                cout << "OK" << "\n";
            }
            else {
                cout << "FAIL" << "\n";
            }
        }
        if (command == '-') {
            if (table.remove(s)) {
                cout << "OK" << "\n";
            }
            else {
                cout << "FAIL" << "\n";
            }
        }
    }
    return 0;
}
