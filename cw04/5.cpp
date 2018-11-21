#include <iostream>

double max(double a, double b) {
    if (a > b) return a;
    return b;
}

int main() {
    const int MAX = 3;

    int t[MAX][MAX] = {
        {-84, 30, 35}, // -19
        {66, 56, -46}, // 76
        {-76, 74, -20} // -22
        //-94 160 -31
    };

    int rows[MAX] = {};
    int cols[MAX] = {};

    for (int y = 0; y < MAX; y++) 
        for (int x = 0; x < MAX; x++) {
            rows[y] += t[y][x];
            cols[x] += t[y][x];
        }

    int maxRow = rows[0], maxRowIndex = 0, minRow = rows[0], minRowIndex = 0,
        maxCol = cols[0], maxColIndex = 0, minCol = cols[0], minColIndex = 0;

    for (int i = 1; i < MAX; i++) {
        if (rows[i] > maxRow) {
            maxRow = rows[i];
            maxRowIndex = i;
        }

        if (rows[i] < minRow) {
            minRow = rows[i];
            minRowIndex = i;
        }

        if (cols[i] > maxCol) {
            maxCol = cols[i];
            maxColIndex = i;
        }

        if (cols[i] < minCol) {
            minCol = cols[i];
            minColIndex = i;
        }
    }

    double m = maxCol / double(minRow);
    m = max(m, minCol / double(maxRow));
    m = max(m, maxCol / double(maxRow));
    m = max(m, minCol / double(minRow));

    if (m == maxCol / double(minRow))
        std::cout << maxRowIndex << " " << minColIndex;

    else if (m == minCol / double(maxRow))
        std::cout << minRowIndex << " " << maxColIndex;

    else if (m == maxCol / double(maxRow))
        std::cout << maxRowIndex << " " << maxColIndex;

    else if (m == minCol / double(minRow))
        std::cout << minRowIndex << " " << minColIndex;

    std::cout << std::endl;
    
    std::cout << m << std::endl;
    std::cout << maxCol / double(minRow) << std::endl;
    std::cout << minCol / double(maxRow) << std::endl;
    std::cout << maxCol / double(maxRow) << std::endl;
    std::cout << minCol / double(minRow) << std::endl;
    
}
