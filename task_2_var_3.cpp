/**
//Даны два строго возрастающих массива целых чисел A[0..n) и B[0..m) и число k. Найти количество
//таких пар индексов (i, j), что A[i] + B[j] = k. Время работы O(n + m).
//n, m ≤ 100000.
//Указание. Обходите массив B от конца к началу.
**/


#include <iostream>
using namespace std;
void input_data_from_console(int len, int *mas) {
    for (int i = 0; i < len; i++) {
        cin >> mas[i];
    }
}
/**FUNC find_bi_plus_aj_equal_k:
 * Так как у нас 2 сортированных массива по возрастанию
 * Мы складываем, начиная с наибольшего эл-та B(с конца списка B)
 * с наименьшим эл-т A ( с начала А)
 * если сумма == к; count ++
 * если сумма > k; мы начинаем складывать с следующим наибольшим после прошлого эл-том B
 * с эл-тами A, начиная с того, на котором мы закончили ( нам не нужно продолжать складывать
 * тот эл-т наибольший B со следующими эл-тами A, ведь дальше эл-ты А будут только увеличиваться
 * => сумма будет еще больше прошлой = > нужно начинать со следующего наибольшего B
 * если сумма < k; продолжаем складывать числа и искать нужную сумму**/
int find_bi_plus_aj_equal_k(int len_A, int *A, int len_B, int *B, int k) {
    int index_A_to_start_from = 0;
    int count = 0;
    for (int i = len_B - 1; i > -1; i--) {
        for (int j = index_A_to_start_from; j < len_A; j++) {
            int sum = B[i] + A[j];
            if (sum == k) {
                count ++;
            }
            else if (sum > k) {
                index_A_to_start_from = j;
                break;
            }
        }
    }
    return count;
}
int main() {
    int n, m, k;
    cin >> n;
    int *A = new int[n];
    input_data_from_console(n, A);
    cin >> m;
    int *B = new int[m];
    input_data_from_console(m, B);
    cin >> k;
    int answer = find_bi_plus_aj_equal_k(n, A, m, B, k);
    cout << answer;
    return 0;
}
