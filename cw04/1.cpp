#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    int MAX = 4;
    std::cin >> MAX;

    int t[MAX][MAX];

    int yMin = 0, xMin = 0, yMax = MAX, xMax = MAX;

    int liczba = 1;
    while (xMin <= xMax && yMin <= yMax) {
        for (int x = xMin; x < xMax; x++) t[yMin][x] = liczba++;
        yMin++;

        for (int y = yMin; y < yMax; y++) t[y][xMax - 1] = liczba++;
        xMax--;

        for (int x = xMax - 1; x >= xMin; x--) t[yMax - 1][x] = liczba++;
        yMax--;

        for (int y = yMax - 1; y >= yMin; y--) t[y][xMin] = liczba++;
        xMin++;
    }

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            std::cout << std::setw(log10(liczba) + 1) << t[i][j] << " ";
        }
        std::cout << std::endl;
    }
            
}
