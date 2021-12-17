/**
1)Группа людей называется современниками если был такой момент, когда они могли собраться вместе. 
Для этого в этот момент каждому из них должно было уже исполниться 18 лет, но ещё не исполниться 80 лет. 
Дан список Жизни Великих Людей. Необходимо получить максимальное количество современников. В день 18летия 
человек уже может принимать участие в собраниях, а в день 80летия и в день смерти уже не может.
Замечание. Человек мог не дожить до 18-летия, либо умереть в день 18-летия. В этих случаях принимать участие в собраниях он не мог.
2)59461003	
3)https://contest.yandex.ru/contest/30914/problems/2_2/
**/

#include<iostream>

#include<vector>

#include<algorithm>

using namespace std;

struct Event {
    int day;
    int month;
    int year;
    int type;
};

bool operator<(Event a, Event b) {
    if (a.year == b.year) {
        if (a.month == b.month) {
            if (a.day == b.day) {
                return a.type < b.type;
            }
            else {
                return a.day < b.day;
            }
        }
        else {
            return a.month < b.month;
        }
    }
    else {
        return a.year < b.year;
    }
}

bool operator<=(Event a, Event b) {
    if (a.year == b.year) {
        if (a.month == b.month) {
            if (a.day == b.day) {
                return a.type <= b.type;
            }
            else {
                return a.day <= b.day;
            }
        }
        else {
            return a.month <= b.month;
        }
    }
    else {
        return a.year <= b.year;
    }
}

struct BinaryTree {

private:

    vector<Event> tree;
    int count_elems = 0;
    int size;

public:

    explicit BinaryTree(int size_tree) {
        vector<Event> a(size_tree);
        swap(a, tree);
        size = size_tree;
    }

    void insert(Event elem) {
        tree[count_elems].day = elem.day;
        tree[count_elems].month = elem.month;
        tree[count_elems].year = elem.year;
        tree[count_elems].type = elem.type;
        count_elems++;
        int i = count_elems - 1;
        while (i >= 0 && tree[i] < tree[(i - 1) / 2]) {
            swap(tree[i], tree[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void remove_min() {
        swap(tree[0], tree[--size]);
        int i = 0;
        while (2 * i + 1 < size) {
            int j = 2 * i + 1;
            if (2 * i + 2 < size && tree[2 * i + 2] < tree[j]) {
                j = 2 * i + 2;
            }
            if (tree[i] <= tree[j]) {
                break;
            } else {
                swap(tree[i], tree[j]);
                i = j;
            }
        }
    }

    Event get_min() {
        return tree[0];
    }
};

void HeapSort(vector<Event> &a, int size) {
    BinaryTree tree(size);
    for (int i = 0; i < size; i++) {
        tree.insert(a[i]);
    }
    vector<Event> c(size);
    for (int i = 0; i < size; i++) {
        c[i].day = tree.get_min().day;
        c[i].month = tree.get_min().month;
        c[i].year = tree.get_min().year;
        c[i].type = tree.get_min().type;
        tree.remove_min();
    }
    swap(c, a);
}


int main() {
    int n;
    cin >> n;
    int j = 0;
    vector<Event> events(n * 2, {0, 0, 0, 0});
    for (int i = 0; i < n; i++) {
        int day_born, month_born, year_born, day_death, month_death, death_year;
        cin >> day_born >> month_born >> year_born >> day_death >> month_death >> death_year;
        if (year_born + 18 > death_year) {
            continue;
        }
        else if (year_born + 18 == death_year && month_born > month_death) {
            continue;
        }
        else if (year_born + 18 == death_year && month_born == month_death && day_born >= day_death) {
            continue;
        }
        else {
            events[j] = Event({day_born, month_born, year_born + 18, 1});
            j++;
        }
        if (death_year - year_born > 80) {
            events[j] = Event({day_born, month_born, year_born + 80, -1});
            j++;
        }
        else if (death_year - year_born >= 80 && month_born < month_death) {
            events[j] = Event({day_born, month_born, year_born + 80, -1});
            j++;
        }
        else if (death_year - year_born >= 80 && month_born <= month_death && day_born <= day_death) {
            events[j] = Event({day_born, month_born, year_born + 80, -1});
            j++;
        }
        else {
            events[j] = Event({day_death, month_death, death_year, -1});
            j++;
        }
    }
    HeapSort(events, n * 2);
    int count = 0;
    int answer = 0;
    for (auto event: events) {
        count += event.type;
        answer = max(answer, count);
    }
    cout << answer;
    return 0;
}
