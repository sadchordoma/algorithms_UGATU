/**
1)Дан отсортированный массив целых чисел A[0..n-1] и массив целых чисел B[0..m-1].
Для каждого элемента массива B[i] найдите минимальный индекс k минимального элемента массива A,
равного или превосходящего B[i]: A[k] >= B[i]. Если такого элемента нет, выведите n.
n, m ≤ 10000.
2)	54391323
3) https://contest.yandex.ru/contest/29212/problems/3_1/
**/

#include <iostream>

void input_data_from_console_(int len, int *mas) 
{
    for ( int i = 0; i < len; i++ ) 
    {
        std::cin >> mas[i];
    }
}

void find_min_index_min_element_aj_more_bi(int m, const int* B, int n, const int* A) 
{
    for ( int i = 0; i < m; i++ ) 
    {
        int there_is_element = 0;
        for ( int j = 0; j < n; j++ ) 
        {
            if (A[j] >= B[i]) 
            {
                std::cout << j << " ";
                there_is_element++;
                break;
            }
        }
        if (there_is_element == 0) 
        {
            std::cout << n << " ";
        }
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;
    int* A = new int[n];
    int* B = new int[m];
    
    input_data_from_console_(n, A);
    input_data_from_console_(m, B);
    
    find_min_index_min_element_aj_more_bi(m, B, n, A);
    
    delete[] A;
    delete[] B;
    return 0;
}
