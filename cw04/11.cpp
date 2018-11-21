#include <iostream>

const int MAX = 3;

bool are_friends(int n, int m) {
    bool digitsN[10] = {};
    bool digitsM[10] = {};

    while (n > 0) {
        digitsN[n%10] = true;
        n /= 10;
    }

    while (m > 0) {
        digitsM[m%10] = true;
        m /= 10;
    }

    for (int i = 0; i < 10; i++) 
        if (digitsM[i] != digitsN[i]) return false;

    return true;
}

int friendly_neighbours(int t[MAX][MAX]) {
    int retval = 0;
    for (int y = 0; y < MAX; y++) {
        for (int x = 0; x < MAX; x++) {
            bool friends = true;

            friends = friends && (y == 0       || are_friends(t[y][x], t[y-1][x]));
            friends = friends && (y == MAX - 1 || are_friends(t[y][x], t[y+1][x]));
            friends = friends && (x == 0       || are_friends(t[y][x], t[y][x-1]));
            friends = friends && (x == MAX - 1 || are_friends(t[y][x], t[y][x+1]));

            if (friends) {
                retval++;
                std::cout << y << " " << x << std::endl;
            }
        }
    }

    return retval;
}

int main() {
    int t[MAX][MAX] = {
        {10, 10, 10},
        {8, 10, 2},
        {7, 6, 5}
    };

    std::cout << friendly_neighbours(t);
    
}
