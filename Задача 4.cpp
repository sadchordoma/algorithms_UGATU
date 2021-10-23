/**
1)Дан массив целых чисел A[0..n), n не превосходит 100 000.
Так же задан размер некотрого окна (последовательно расположенных
элементов массива) в этом массиве k, k<=n. Требуется для каждого
положения окна (от 0 и до n-k) вывести значение максимума в окне.
Скорость работы O(n log n), память O(n).

2)54886924

3)https://contest.yandex.ru/contest/29212/problems/6_4/

**/

#include <iostream>

#include <queue>

int main() 
{
    int len_numbers, window_shift;
    std::cin >> len_numbers;
    int* numbers = new int[len_numbers];
    
    for ( int i = 0; i < len_numbers; i++ ) 
    {
        std::cin >> numbers[i];
    }
    
    std::cin >> window_shift;
    std::priority_queue<std::pair<int, int>> heap_with_numbers_and_indexes;
    
    for ( int index = 0; index < window_shift; index++ ) 
    {
        heap_with_numbers_and_indexes.push(std::make_pair(numbers[index], index));
    }
    
    for ( int index = 0; index <= len_numbers - window_shift; index++ ) 
    {
        std::pair<int, int> top_element = heap_with_numbers_and_indexes.top();
        while (top_element.second < index) 
        {
            heap_with_numbers_and_indexes.pop();
            top_element = heap_with_numbers_and_indexes.top();
        }
        std::cout << top_element.first << " ";
        int next_index_number = index + window_shift;
        
        if ( next_index_number < len_numbers ) 
        {
            heap_with_numbers_and_indexes.push(std::make_pair(numbers[next_index_number], next_index_number));
        }
    }
    delete[] numbers;
    return 0;
}
