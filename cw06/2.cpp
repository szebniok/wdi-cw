#include <iostream>

const int N = 5;

bool loop(int odw[N], int masa, int i) {
    if (i == N) return false;
    if (odw[i] == masa) return true;

    return loop(odw, masa - odw[i], i + 1) || loop(odw, masa + odw[i], i + 1) || loop(odw, masa, i + 1);
}

bool odwaz(int odw[N], int masa) {
    return loop(odw, masa, 0);
}

int main() {
    int odw[N] = {10, 10, 50, 100, 200};

    int n;
    std::cin >> n;
    std::cout << (odwaz(odw, n) ? "TAK" : "NIE");
}
