#include <iostream>

bool have_at_least_one_even_digit(int n) {
    while (n > 0) {
        if (n % 2 == 0) return true;
        n /= 10;
    }
    return false;
}

int main() {
    const int MAX = 7;
    int t[MAX][MAX] = {
        {13,13,13,13,79,13,57},    
        {13,13,13,13,79,13,57},    
        {13,13,13,13,79,13,57},    
        {13,13,13,13,79,13,57},    
        {13,13,13,13,79,13,57},    
        //{3,23,13,13,79,13,57},    
        {88,22,22,23,68,28,88},
        {13,13,13,13,79,13,57}    
    };

    bool result = false;
    for (int y = 0; y < MAX; y++) {
        bool r = true;
        for (int x = 0; x < MAX; x++) {
            r = r && have_at_least_one_even_digit(t[y][x]); 
        }
        result = result || r;
    }
    std::cout << (result ? "TAK" : "NIE");
    return 0;
}
    

