/*
 * „Waga” liczby jest określona jako ilość różnych czynników pierwszych liczby. Na
 * przykład waga(1)=0, waga(2)=1, waga(6)=2, waga(30)=3, waga(64)=1. Dana jest
 * tablica: int t[N]. Tablica zawiera liczby naturalne. Proszę napisać funkcję, która
 * sprawdza czy można elementy tablicy podzielić na 3 podzbiory o równych wagach. Do
 * funkcji należy przekazać wyłącznie tablicę, funkcja powinna zwrócić wartość typu
 * bool.
 */

#include <iostream>

const int N = 7;

int waga(int n) {
    if (n == 1) return 0;
    int retval = 0, i = 2;
    while (n > 1) {
        if (n % i == 0) retval++;
        while (n % i == 0) n /= i;
        i++;
    }

    return retval;
}

bool loop(int t[N], int i, int suma1, int suma2, int suma3) {
    if (suma1 == suma2 && suma2 == suma3 && suma3 != 0) return true;
    if (i == N) return false;

    return loop(t, i + 1, suma1 + t[i], suma2, suma3) ||
           loop(t, i + 1, suma1, suma2 + t[i], suma3) ||
           loop(t, i + 1, suma1, suma2, suma3 + t[i]) ||
           loop(t, i + 1, suma1, suma2, suma3);
}

bool ma_3_podzbiory(int t[N]) {
    int w[N];
    for (int i = 0; i < N; i++) w[i] = waga(t[i]);

    return loop(w, 0, 0, 0, 0);
}

int main() {
    int t[N] = {1, 2, 3, 5, 30, 6, 64};
    std::cout << (ma_3_podzbiory(t) ? "TAK" : "NIE");
}
