#include <iostream>

int main() {
    const int N = 3;
    const int M = 10 * N;
    int t1[10][N] = {
        {1, 2, 3},    
        {1, 2, 3},    
        {1, 2, 3},    
        {1, 2, 3},    
        {1, 2, 3},    
        {1, 2, 3},    
        {1, 2, 3},    
        {1, 2, 3},    
        {1, 2, 3},    
        {1, 2, 3}
    };
    int t2[M] = {};

    int max = t1[0][N - 1];
    for (int i = 1; i < 10; i++)
        if (max < t1[i][N - 1])
            max = t1[i][N - 1];

    int offset[10] = {};

    int m = M;
    for (int i = 0; i < m; i++) {

        int min = max;
        int minIndex;
        for (int y = 0; y < 10; y++) {
            if (offset[y] < N && t1[y][offset[y]] < min) {
                minIndex = y;
                min = t1[y][offset[y]];
            }
//            if (offset[y] < N && i > 0 && t1[y][offset[y]] == t2[i - 1]) offset[y]++;
        }

//        std::cout << t2[i - 1] << " " min;

        if (i == 0) t2[i] = min;
        else if (i > 0 && t2[i-1] < min)
            t2[i] = min;
        else {
            i--;
            m--;
        }
        offset[minIndex]++;
    }

    for (int i = 0; i < M; i++) std::cout << t2[i] << " ";
}
