/**
1)Найдите все вхождения шаблона в строку. Длина шаблона – p, длина строки – n. Время O(n + p), доп. память – O(p).
p ≤ 30000, n ≤ 300000.
2)68542769
3)https://contest.yandex.ru/contest/37787/problems/1/
**/
#include <iostream>
#include <vector>

using namespace std;

void z_func(vector<size_t> &z_mas, string pattern, string text) {
    text = pattern + "$" + text;
    size_t len = text.size();
    z_mas.resize(len, 0);
    z_mas[0] = len;
    for (size_t current = 1, left = 0, right = 1; current < len; current++) {
        if (current >= right) {
            size_t off = 0;
            while (current + off < len && text[current + off] == text[off]) {
                off++;
            }
            z_mas[current] = off;
            right = current + z_mas[current];
            left = current;
        }
        else {
            size_t equiv = current - left;
            if (z_mas[equiv] < right - current) {
                z_mas[current] = z_mas[equiv];
            }
            else {
                size_t off = 0;
                while (right + off < len && text[right - current + off] == text[right + off]) {
                    off++;
                }
                z_mas[current] = right - current + off;
                right += off;
                left = current;
            }
        }
    }
}

int main() {
    vector<size_t> z_mas;
    string pattern, text;
    cin >> pattern >> text;
    z_func(z_mas, pattern, text);
    size_t len_pattern = pattern.size();
    for (size_t i = 0; i < z_mas.size(); i++) {
        if (z_mas[i] == len_pattern) {
            cout << i - len_pattern - 1 << " ";
        }
    }
    return 0;
}
