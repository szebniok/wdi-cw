#include <iostream>

bool have_odd_digits(int n) {
    while (n > 0) {
        if (n % 2 == 0) return false;
        n /= 10;
    }
    return true;
}

int main() {
    const int MAX = 7;
    int t[MAX][MAX] = {
        {13,13,13,13,79,13,57},    
        {13,13,13,13,79,13,57},    
        {13,13,13,13,79,13,57},    
        {13,13,13,13,79,13,57},    
        {13,13,13,13,79,13,57},    
        {88,22,22,13,68,28,88},
        {13,13,13,13,79,13,57}    
    };

    for (int y = 0; y < MAX; y++) {
        bool result = false;
        for (int x = 0; x < MAX; x++) {
            result = result || have_odd_digits(t[y][x]); 
        }
        if (! result) {
            std::cout << "NIE";
            return -1;
        }
    }
    std::cout << "TAK";
    return 0;
}
    

