/**
 1)https://contest.yandex.ru/contest/29212/problems/3_1/
 * Дан отсортированный массив целых чисел A[0..n-1] и массив целых чисел B[0..m-1]. 
 * Для каждого элемента массива B[i] найдите минимальный индекс k минимального элемента массива A,
 * равного или превосходящего B[i]: A[k] >= B[i]. Если такого элемента нет, выведите n.

n, m ≤ 10000.
2)	53789954
ПЕРЕДЕЛАТЬ DELETE .>>>>>>>>>>>>>>>>>>
**/
#include <iostream>
using namespace std;

void input_data_from_console_(int len, int *mas) {   // compilator rugaetsya 4to func uje est' v projecte
    for (int i = 0; i < len; i++) {
        cin >> mas[i];
    }
}

void find_min_index_min_element_aj_more_bi(int m, int* B, int n, int* A) {
    for (int i = 0; i < m; i++) {
        int there_is_element = 0;
        for (int j = 0; j < n; j++) {
            if (A[j] >= B[i]) {
                cout << j << " ";
                there_is_element ++;
                break;
            }
        }
        if (there_is_element == 0) {
            cout << n << " ";
        }
    }
}


int main() {
    int n, m;
    cin >> n >> m;
    int* A = new int[n];
    int* B = new int[m];
    input_data_from_console_(n, A);
    input_data_from_console_(m, B);
    find_min_index_min_element_aj_more_bi(m, B, n, A);
    return 0;
}
