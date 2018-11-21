#include <iostream>

const int MAX = 4;

bool lewy_mniejszy(int lewy[MAX], int prawy[MAX]) {
    for (int i = 0; i < MAX; i++) {
        if (lewy[i] < prawy[i]) return true;
        if (prawy[i] < lewy[i]) return false;
    }
    return true;
}

int max_roz(int t[MAX][MAX]) {
    int *min = t[0], minIndex = 0;
    int *max = t[0], maxIndex = 0;

    for (int i = 1; i < MAX; i++) {
        if (lewy_mniejszy(t[i], min)) {
            minIndex = i;
            min = t[i];
        }

        if (lewy_mniejszy(max, t[i])) {
                maxIndex = i;
                max = t[i];
        }
    }

    return (maxIndex > minIndex) ? maxIndex - minIndex : minIndex - maxIndex;
}

int main() {
    int t[MAX][MAX] = {
        {0, 0, 0, 0},
        {1, 0, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 0, 1}
    };

    std::cout << max_roz(t);
}
