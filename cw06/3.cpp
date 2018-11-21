#include <iostream>

const int N = 5;

bool loop(int odw[N], int masa, int i, bool lewe[N], bool prawe[N]) {
    if (i == N) return false;
    if (odw[i] == masa) {
        prawe[i] = true;
        for (int j = 0; j < N; j++)
            if (lewe[j])
                std::cout << odw[j] << " ";

        std::cout << " | ";

        for (int j = 0; j < N; j++)
            if (prawe[j])
                std::cout << odw[j] << " ";

        return true;
    }

    // wstawiamy po prawej
    prawe[i] = true;
    bool retval = loop(odw, masa - odw[i], i + 1, lewe, prawe);
    if (retval) return true;

    // wstawiamy po lewej
    prawe[i] = false;
    lewe[i] = true;
    retval = loop(odw, masa + odw[i], i + 1, lewe, prawe);
    if (retval) return true;

    // nie wstawiamy
    lewe[i] = false;
    return loop(odw, masa, i + 1, lewe, prawe);
}

bool odwaz(int odw[N], int masa) {
    bool lewe[N] = {}; // odwazniki po stronie przedmiotu
    bool prawe[N] = {};
    return loop(odw, masa, 0, lewe, prawe);
}

int main() {
    int odw[N] = {10, 10, 50, 100, 200};

    int n;
    std::cin >> n;
    std::cout << std::endl << (odwaz(odw, n) ? "TAK" : "NIE");
}
