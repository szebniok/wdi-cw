#include <iostream>

const int MAX = 3;

bool has_at_least_one_even_digit(int n) {
    while (n > 0) {
        if (n % 2 == 0) return true;
        n /= 10;
    }
    return false;
}

bool f(int t[MAX][MAX]) {
    for (int y = 0; y < MAX; y++) {
        bool result = true;
        for (int x = 0; x < MAX; x++) 
            result = result && has_at_least_one_even_digit(t[y][x]);
        if (result) return true;
    }
    return false;
}

int main() {
   int t[MAX][MAX] = {
        {12, 33, 88},
        {12, 71, 82},
        {18, 77, 68}
   };

   std::cout << (f(t) ? "TAK" : "NIE");
}
