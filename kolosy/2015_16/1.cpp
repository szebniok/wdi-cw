#include <iostream>
#include <cmath>

bool pierwsza(int n) {
    if (n == 1) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    int b = 5;
    while (b <= sqrt(n)) {
        if (n % b == 0) return false;
        b += 2;
        if (n % b == 0) return false;
        b += 4;
    }
    return true;
}

int main() {
    int A;
    std::cin >> A;

    // dla baza = 2 nigdy nie spelnione
    for (int baza = 3; baza <= 16; baza++) {
        int tmp = A;
        bool found = true;
        while (tmp > 0) {
            if (!pierwsza(tmp % baza)) {
                found = false;
                break;
            }
            tmp /= baza;
        }

        if (found) {
            std::cout << "TAK";
            std::cout << baza;
            return 0;
        }
    }
    std::cout << "NIE";
}
