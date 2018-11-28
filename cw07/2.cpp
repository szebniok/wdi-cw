/* Dany jest ciąg zer i jedynek zapisany w tablicy int t[N]. Proszę napisać funkcję,
 * która odpowiada na pytanie czy jest możliwe pocięcie ciągu na kawałki z których
 * każdy reprezentuje liczbę pierwszą. Długość każdego z kawałków nie może przekraczać
 * 30. Na przykład dla ciągu 111011 jest to możliwe, a dla ciągu 110100 nie jest
 * możliwe. */

#include <iostream>

const int N = 6;

bool prime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;

    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i < n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

bool can_cut(int t[N], int i = 0) {
    if (i < N - 1 && t[i] == 0) return can_cut(t, i + 1);
    if (i == N || i == N - 2) return true;
    if (i == N - 1) return false;
    for (int len = 2; len + i < N && len <= 30; len++) {
        int number = 0;
        for (int j = 0; j < len; j++) {
            number <<= 1;
            number += t[i + j]; 
        }

//        std::cout << i << " " << number << std::endl;

        if (prime(number)) {
            if (can_cut(t, i + len)) return true;
        }
    }
    return false;
}

int main() {
    int t[N] = {1, 1, 1, 0, 1, 1}; 
    std::cout << can_cut(t) << std::endl;
    int u[N] = {1, 1, 0, 1, 0, 0};
    std::cout << can_cut(u);
}
