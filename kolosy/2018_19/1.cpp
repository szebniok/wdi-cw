#include <iostream>

const int MAX = 9;

int nwd(int a, int b) {
    while (a != b) {
        if (a > b) a -= b;
        if (b > a) b -= a;
    }
    return a;
}

int dlugosc(int t[MAX]) {
    int wynik = -1;
    int curr = 0;
    for (int i = 0; i < MAX - 1; i++) {
        if (nwd(t[i], t[i + 1]) == 1) {
            curr++;
        } else {
            //if (wynik < curr) wynik = curr + 1;
            if (wynik < curr + 1) wynik = curr + 1;

            // tu mam raczej blad
            curr = 0;
        }
    }

    // if (wynik < curr) wynik = curr;
    if (wynik < curr + 1) wynik = curr + 1;

    return wynik;
}

int main() {

    int t[MAX] = {7, 6, 5, 4, 2, 3, 4, 5, 10};

    std::cout << dlugosc(t);

}
