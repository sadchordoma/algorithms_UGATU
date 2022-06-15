/**
1)Строка называется палиндромом, если она одинаково читается как слева направо, так и справа налево. Например, «abba» – палиндром, а «roman» – нет.
Для заданной строки s длины n (1 ≤ n ≤ 105) требуется подсчитать число пар (i, j), 1 ≤ i < j ≤ n, таких что подстрока s[i..j] является палиндромом.
2)68638627
3)https://contest.yandex.ru/contest/37787/problems/3/
**/
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    auto n = s.length();
    vector<int> d1 (n);
    int l = 0;
    int r = -1;
    for (int i = 0; i < n; i++) {
        int k = i > r ? 1 : min (d1[l + r - i], r - i + 1);
        while (i + k < n && i - k >= 0 && s[i + k] == s[i - k]) {
            k++;
        }
        d1[i] = k;
        if (i + k - 1 > r ) {
            l = i - k + 1;
            r = i + k - 1;
        }
    }
    vector<int> d2 (n);
    l = 0;
    r = -1;
    for (int i = 0; i < n; i++) {
        int k = i > r ? 0 : min (d2[l + r - i + 1], r - i + 1);
        while (i + k < n && i - k - 1 >= 0 && s[i + k] == s[i - k - 1]) {
            k++;
        }
        d2[i] = k;
        if (i + k - 1 > r) {
            l = i - k;
            r = i + k - 1;
        }
    }
    long long int count = 0;
    for (int i = 0; i < n; i++) {
        d1[i]--;
        count += d1[i] + d2[i];
    }
    cout << count;
    return 0;
}
