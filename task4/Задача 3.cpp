/**
1)Реализовать очередь с помощью двух стеков. Использовать стек, реализованный 
с помощью динамического буфера.

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
 
2)54390095
 
3)https://contest.yandex.ru/contest/29212/problems/4_3/

**/

#include <iostream>

class stack {

private:
    int buffer_size = 0;
    int *buffer;
    int back_index = 0;
    int count_elements = 0;
    int top_index = 0;

public:
    stack(int buffer_size_) {
        buffer_size = buffer_size_;
        buffer = new int[buffer_size_];
    }

    ~stack() {
        delete[] buffer;
    }

    int empty() {
        if (count_elements > 0) {
            return 0;
        } else {
            return 1;
        }
    }

    int push_back(int element) {
        count_elements++;
        buffer[back_index++] = element;
        return element;
    }

    int pop_front() {
        if (count_elements <= 0) {
            return -1;
        } else {
            count_elements--;
            return buffer[top_index++];
        }
    }
};

int main() {
    int n;
    std::cin >> n;
    stack Start(n), End(n);
    while (n--) {
        int a, b;
        std::cin >> a >> b;
        if (a == 3) {
            Start.push_back(b);
        }
        else {
            if (End.empty()) {
                while (!Start.empty()) {
                    End.push_back(Start.pop_front());
                }
            }
            if (End.pop_front() == b) {
                continue;
            }
            else {
                std::cout << "NO";
                return 0;
            }
            }
        }
    std::cout << "YES";
    return 0;
}

