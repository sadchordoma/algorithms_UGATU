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
