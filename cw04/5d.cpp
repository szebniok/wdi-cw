#include <iostream>

double max(double a, double b) {
    if (a > b) return a;
    return b;
}

double min(double a, double b) {
    if (a < b) return a;
    return b;
}

int main() {
    const int MAX = 3;

    int t[MAX][MAX] = {
        {-32, 86, -84}, // -146
        {-14, -72, -85},    // -45
        {-68, 60, -15} // -220
        //-125 -156 -130
    };

    int rows[MAX] = {};
    int cols[MAX] = {};

    for (int y = 0; y < MAX; y++) 
        for (int x = 0; x < MAX; x++) {
            rows[y] += t[y][x];
            cols[x] += t[y][x];
        }

    // both positive
    int maxColumn = cols[0], minColumn = cols[0];
    int maxColumnIndex = 0; minColumnIndex = 0;
    int maxRow = rows[0], minRow = [0];
    int maxRowIndex = 0; minRowIndex = 0;

    for (int y = 1; y < MAX; y++) {
        maxColumn = max(maxColumn, cols[y]);
        minColumn = min(minColumn, cols[y]);
        maxRow = max(maxRow, rows[y]);
        minRow = min(minRow, rows[y]);
    }




    std::cout << std::endl;
}
