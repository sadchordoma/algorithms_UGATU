/**
 * 1)Реализовать очередь с помощью двух стеков. Использовать стек, реализованный
 * с помощью динамического буфера.

Обрабатывать команды push back и pop front.

Формат ввода
В первой строке количество команд n. n ≤ 1000000.

Каждая команда задаётся как 2 целых числа: a b.

a = 2 - pop front
a = 3 - push back

Если дана команда pop front, то число b - ожидаемое значение. Если команда
 pop front вызвана для пустой структуры данных, то ожидается “-1”.

Формат вывода
Требуется напечатать YES - если все ожидаемые значения совпали.
 Иначе, если хотя бы одно ожидание не оправдалось, то напечатать NO.
 2)53836931
 3)https://contest.yandex.ru/contest/29212/problems/4_3/
 **/
#include <iostream>
using namespace std;
class queue {
private:
    int* buffer;
    int buffer_size;
    int back_index = 0;
    int top_index = -1;
    int count_elements = 0;
    void increase_buffer(int* buffer, int length) {
        int new_length = length * 3 / 2;
        int* new_buffer = new int[new_length];
        for (int i = 0; i < length; i++) {
            if (buffer[i] != -1) {
                new_buffer[i] = buffer[i];
                back_index = i;
            }
        }
        delete[] buffer;
        buffer = new_buffer;
        length = new_length;
        buffer_size = new_length;
        delete[] new_buffer;
    }
public:
    queue(int buffer_size) {
        buffer = new int[buffer_size];
        buffer_size = buffer_size;
    }
    ~queue() {
        delete[] buffer;
    }
    int push_back(int a) {
        if (top_index == -1)
            {top_index = 0;}
        if (back_index + 1 > buffer_size)
            { increase_buffer(buffer, buffer_size);}
        buffer[back_index] = a;
        buffer_size ++;
        count_elements ++;
        return buffer[back_index++];
    }
    int pop_front() {
        if (top_index == -1 || top_index + 1 > buffer_size || count_elements <= 0)
            {return -1;}
        buffer_size --;
        count_elements --;
        int to_pop = buffer[top_index++];
        buffer[top_index - 1] = -1;
        return to_pop;
    }
};


int compare_answers(queue stk, int n) {
    for (int i = 0; i < n; i++) {
        int a, b;
        bool check_correct_answer;
        cin >> a >> b;
        if (a == 3) {
            check_correct_answer = stk.push_back(b) == b;
        }
        if (a == 2) {
            check_correct_answer = stk.pop_front() == b;
        }
        if (check_correct_answer == 1) {
            continue;
        }
        else {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}


int main() {
    int n;
    cin >> n;
    queue stk(n);
    compare_answers(stk, n);
    return 0;
}
