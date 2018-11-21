#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;

    bool digit[16];

    for (int baza = 2; baza <= 16; baza++) {
        int tmpA = a, tmpB = b;
        for (int i = 0; i < 16; i++) digit[i] = false;

        while (tmpA > 0) {
            digit[tmpA % baza] = true;
            tmpA /= baza;
        }

        bool found = true;
        while (tmpB > 0) {
            if (digit[tmpB % baza]) {
                found = false;
                break;
            }
            tmpB /= baza;
        }

        if (found) {
            std::cout << baza;
            return 0;
        }
    }

    std::cout << "BRAK";
}
