#include <iostream>

double max(double a, double b) {
    if (a > b) return a;
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

    int maxRowPositive = rows[0], maxRowPositiveIndex = 0, minRowPositive = rows[0], minRowPositiveIndex = 0,
        maxRowNegative = rows[0], maxRowNegativeIndex = 0, minRowNegative = rows[0], minRowNegativeIndex = 0,
        maxColPositive = rows[0], maxColPositiveIndex = 0, minColPositive = rows[0], minColPositiveIndex = 0,
        maxColNegative = rows[0], maxColNegativeIndex = 0, minColNegative = rows[0], minColNegativeIndex = 0;

    for (int i = 0; i < MAX; i++) {

        if (rows[i] >= 0) {
            if (rows[i] > maxRowPositive) {
                maxRowPositive = rows[i];
                maxRowPositiveIndex = i;
            }

            if (rows[i] < minRowPositive) {
                minRowPositive = rows[i];
                minRowPositiveIndex = i;
            }
        } else {
            if (rows[i] > maxRowNegative) {
                maxRowNegative = rows[i];
                maxRowNegativeIndex = i;
            }

            if (rows[i] < minRowNegative) {
                minRowNegative = rows[i];
                minRowNegativeIndex = i;
            }
        }

        if (cols[i] >= 0) {
            if (cols[i] > maxColPositive) {
                maxColPositive = cols[i];
                maxColPositiveIndex = i;
            }

            if (cols[i] < minColPositive) {
                minColPositive = cols[i];
                minColPositiveIndex = i;
            }
        } else {
            if (cols[i] > maxColNegative) {
                maxColNegative = cols[i];
                maxColNegativeIndex = i;
            }

            if (cols[i] < minColNegative) {
                minColNegative = cols[i];
                minColNegativeIndex = i;
            }
        }
    }

    double m = maxColPositive / double(minRowPositive);
    m = max(m, minColNegative / double(maxRowNegative));
    m = max(m, minColPositive / double(minRowNegative));
    m = max(m, minColNegative / double(maxRowPositive));

    if (m == maxColPositive / double(minRowPositive))
        std::cout << minRowPositiveIndex << " " << maxColPositiveIndex;

    else if (m == minColNegative / double(maxRowNegative))
        std::cout << maxRowNegativeIndex << " " << minColNegativeIndex;

    else if (m == minColPositive / double(minRowNegative))
        std::cout << minRowNegativeIndex << " " << minColPositiveIndex;

    else if (m == minColNegative / double(maxRowPositive))
        std::cout << minRowPositiveIndex << " " << minColNegativeIndex;

    std::cout << std::endl;
}
