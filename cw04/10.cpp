#include <iostream>

const int MAX = 3;

bool has_0(int t[MAX][MAX]) {
    bool row[MAX] = {};
    bool col[MAX] = {};

    for (int y = 0; y < MAX; y++) {
        for (int x = 0; x < MAX; x++) {
            if (t[y][x] == 0) {
                row[y] = true;
                col[x] = true;
            }
        }
    }

    for (int i = 0; i < MAX; i++) 
        if (row[i] && col[i] == false) return false;

    return true;
        
}

int main() {
    int t[MAX][MAX] = {
        {0, 1, 0},
        {0, 0, 2},
        {0, 1, 2}
    };

    std::cout << (has_0(t) ? "TAK" : "NIE");
    
}
