#include <iostream>

const int MAX = 4;

bool end(int offset[MAX]) {
    for (int i = 0; i < MAX; i++)
        if (offset[i] < MAX) return false;
    return true;
}

void print(int offset[MAX]) {
    for (int i = 0; i < MAX; i++)
        std::cout << offset[i] << " ";
    int x;
    std::cin >> x;
}

void f(int t1[MAX][MAX], int t2[MAX*MAX]) {
    for (int i = 0; i < MAX*MAX; i++) {
        t2[i] = 0;
    }
    int i = 0;

    int offset[MAX] = {};

    bool found = true;

    while (! end(offset)) {
        for (int y = 0; y < MAX; y++) {

            if (offset[y] == MAX) continue;

            bool found_lower = false;
            for (int j = y + 1; j < MAX; j++) {
                if (t1[j][offset[j]] <= t1[y][offset[y]]) {
                    found_lower = true;
                    break;
                }
            }

            if (found_lower) continue;

            t2[i++] = t1[y][offset[y]++];
            y--;

            print(offset);
        }
    }
}

int main() {
    int t1[MAX][MAX] = {
        {1, 2, 3, 4},
        {2, 4, 7, 77},
        {5, 7, 8, 9},
        {9, 10, 22, 33}
    };


    int t2[MAX*MAX];
    f(t1, t2);


    for (int i = 0; i < MAX * MAX; i++)
        std::cout << t2[i] << " ";
}
