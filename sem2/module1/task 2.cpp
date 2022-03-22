/**
1)В город N приехал цирк с командой атлетов. Они хотят удивить горожан города N — выстроить из своих тел башню максимальной высоты.
Башня — это цепочка атлетов, первый стоит на земле, второй стоит у него на плечах, третий стоит на плечах у второго и т.д.
Каждый атлет характеризуется силой si (kg) и массой mi (kg). Сила — это максимальная масса, которую атлет способен держать у себя на плечах.
К сожалению ни один из атлетов не умеет программировать, так как всю жизнь они занимались физической подготовкой, и у них не было времени 
на изучение языков программирования. Помогите им, напишите программу, которая определит максимальную высоту башни, которую они 
могут составить. Известно, что если атлет тяжелее, то он и сильнее: если mi>mj, то si > sj. Атлеты равной массы могут иметь различную силу.
2)65742733
3)https://contest.yandex.ru/contest/35212/problems/2_1/
**/

#include <iostream>

#include <vector>

#include <algorithm>

using namespace std;

int main() {
    int n = 0;
    vector<pair<int, int>> atlets;
    int m, s;
    while(cin >> m >> s){
        atlets.push_back({m, s});
        n++;
    }

    sort(atlets.begin(), atlets.end());

    vector<int> cur_strength;
    vector<int> cur_weight;
    cur_strength.push_back(atlets[0].second);
    cur_weight.push_back(atlets[0].first);
    int h = 1;
    bool is_satisfy = true;
    int all_weight = 0;
    int i = 1;
    for (i; i < n; i++) {
        is_satisfy = true;
        all_weight = 0;
        for (int j = 0; j < cur_weight.size(); j++) {
            if (atlets[i].second >= cur_weight[j]) {
                all_weight += cur_weight[j];
            }
            else {
                is_satisfy = false;
                break;
            }
        }
        if (is_satisfy && atlets[i].second - all_weight >= 0) {
            cur_strength.push_back(atlets[i].second - all_weight);
            cur_weight.push_back(atlets[i].first);
            h++;
        }
    }
    cout << h;
    return 0;
}
