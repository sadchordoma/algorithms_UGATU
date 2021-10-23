/**
1)Дано натуральное число N. Представить N в виде A + B, так, что НОД(A, B) максимален, 1 ≤ A ≤ B.
Вывести A и B. Если возможно несколько ответов - вывести ответ с минимальным A.
1 < n ≤ 10 000 000.
2)54391624
3)https://contest.yandex.ru/contest/29212/problems/1_4/
**/

#include <iostream>

int find_first_del(int number)
{
    int d = 2;
    while (d * d < number)
    {
        if (number % d == 0)
        {
            return number / d; // в первый раз находим наимешьний делитель,
        }                      // тогда его напарник будет наибольшим всегда
        d += 1;
    }

    if (d * d == number)
    { // если не нашлось делителя раньше, значит это
        return d;          // число явл квадратом простого числа, берем его корень
    }
    return 1; // если число - простое - выводим просто 1
}

int main()
{
    int N, A, B;
    std::cin >> N;
    A = find_first_del(N);
    B = N - A;
    std::cout << A << " " << B;
    return 0;
}
