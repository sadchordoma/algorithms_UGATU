/**
1)Дана очень длинная последовательность целых чисел длины n. Требуется вывести в отсортированном виде её наименьшие k элементов. 
Последовательность может не помещаться в память. Время работы O(n * log(k)). Доп. память O(k). Использовать слияние.
2)59438378	
3)https://contest.yandex.ru/contest/30914/problems/4_1/
**/

#include <cstring>

#include <iostream>

using namespace std;

void Merge(int *a, int a_len, int *b, int len_b, int *c) {
    int i = 0, j = 0;
    while (i < a_len && j < len_b) {
        if (a[i] <= b[j]) {
            c[i + j] = a[i];
            i++;
        } else {
            c[i + j] = b[j];
            j++;
        }
    }
    while (i < a_len) {
        c[i + j] = a[i];
        i++;
    }
    while (j < len_b) {
        c[i + j] = b[j];
        j++;
    }
}

void MergeSort(int *a, int len_a) {
    if (len_a <= 1) {
        return;
    }
    int firstLen = len_a / 2;
    int secondLen = len_a - firstLen;
    MergeSort(a, firstLen);
    MergeSort(a + firstLen, secondLen);
    int *c = new int[len_a];
    Merge(a, firstLen, a + firstLen, secondLen, c);
    memcpy(a, c, sizeof(int) * len_a);
    delete[] c;
}


void printArr(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void Merge_for_k(int *a, int a_len, int *b, int len_b, int *c, int k) {
    int i = 0, j = 0;
    while (i < a_len && j < len_b && i + j != k) {
        if (a[i] <= b[j]) {
            c[i + j] = a[i];
            i++;
        } else {
            c[i + j] = b[j];
            j++;
        }
    }
    if (j + i != k) {
        if (j == len_b) {
            while (j + i != k) {
                c[i + j] = a[i];
                i++;
            }
        }
        else {
            while (j + i != k) {
                c[i + j] = a[j];
                j++;
            }
        }
    }
}


int main() {
    int n, k;
    cin >> n >> k;
    int * a = new int[k];
    int * b = new int[k];
    for (int i = 0; i < k; i++) {
        b[i] = -190;
    }
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }
    MergeSort(a, k);
    n-=k;
    for (int i = 0; i < n; i++) {
        cin >> b[i % k];
        if (b[k - 1] != -190) {
            MergeSort(b, k);
            int * c = new int[k];
            Merge_for_k(a, k, b, k, c, k);
            memcpy(a, c, sizeof(int) * k);
            delete[] c;
            for (int j = 0; j < k; j++) {
                b[j] = -190;
            }
        }
    }
    int do_or_not = 0;
    for (int i = 0; i < k; i++) {
        if (b[i] != -190) {
            do_or_not += 1;
        }
    }
    if (do_or_not == 0) {
        printArr(a, k);
    }
    else {
        MergeSort(b, do_or_not);
        int * c = new int[k];
        Merge_for_k(a, k, b, do_or_not, c, k);
        printArr(c, k);
        delete[] c;
    }
    delete[] a;
    delete[] b;
    return 0;
}
