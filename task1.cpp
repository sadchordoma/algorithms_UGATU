/**
1)На склад привезли много пустых ящиков. Все ящики пронумерованы по порядку поступления от 0.
Известно, что их все можно сложить один в один (то есть так, что каждый следующий помещается в предыдущий). Один ящик можно вложить в другой, если его можно перевернуть так, что размеры одного ящика по всем осям станут строго меньше размеров другого ящика по соответствующим осям.
Требуется определить, в какой последовательности они будут вложены друг в друга. Вывести номера ящиков.
Максимальное кол-во 10000.
2)57811959
3)https://contest.yandex.ru/contest/30914/problems/1_1/
**/
#include <iostream>

struct boxes {
    long long position;
    long long volume;

};

int main() {
    long long n = 0;
    std::cin >> n;
    boxes *Boxes = new boxes[n];
    for (int order = 0; order < n; order++) {
        long long a = 0, b = 0, c = 0;
        std::cin >> a >> b >> c;
        Boxes[order].position = order;
        Boxes[order].volume = a + b + c;
    }
    boxes tmp;
    for (int i = 1; i < n; ++i) {
        tmp.position = Boxes[i].position;
        tmp.volume = Boxes[i].volume;
        int j = i - 1;
        for (; j >= 0 && tmp.volume < Boxes[j].volume; --j) {
            Boxes[j + 1].volume = Boxes[j].volume;
            Boxes[j + 1].position = Boxes[j].position;
        }
        Boxes[j + 1].volume = tmp.volume;
        Boxes[j + 1].position = tmp.position;
    }

    for (int i = 0; i < n; ++i) {
        std::cout << Boxes[i].position << " ";
    }
    delete[] tmp;
    delete[] Boxes;
    return 0;
}
