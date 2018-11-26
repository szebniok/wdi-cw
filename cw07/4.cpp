/* Szachownica jest reprezentowana przez tablicę int t[8][8] wypełnioną liczbami
 * naturalnymi zawierającymi koszt przebywania na danym polu szachownicy. Król
 * szachowy znajduje się w wierszu 0 i kolumnie k. Król musi w dokładnie 7 ruchach
 * dotrzeć do wiersza 7. Proszę napisać funkcję, która wyznaczy minimalny koszt
 * przejścia króla. Do funkcji należy przekazać tablicę t oraz startową kolumnę k.
 * Koszt przebywania na polu startowym i ostatnim także wliczamy do kosztu przejścia.
 */

#include <iostream>
#include <algorithm>

const int N = 8;

int walk(int k, int row, const int cost[N][N]) {
    if (row == N - 1) return cost[row][k];

    int retval = walk(k, row + 1, cost);

    if (k > 0)     retval = std::min(retval, walk(k - 1, row + 1, cost));
    if (k < N - 1) retval = std::min(retval, walk(k + 1, row + 1, cost));
    
    return retval + cost[row][k];
}

int main() {
    const int cost[N][N] = {
        {0, 0, 0, 4, 0, 0, 0, 0},
        {0, 0, 1, 4, 2, 0, 0, 0},
        {0, 1, 0, 4, 2, 9, 0, 0},
        {9, 9, 3, 4, 9, 8, 0, 0},
        {9, 9, 9, 4, 1, 0, 1, 0},
        {9, 9, 0, 4, 2, 3, 2, 0},
        {9, 9, 0, 4, 3, 0, 3, 0},
        {9, 9, 1, 4, 1, 9, 4, 0},
    };

    int k;
    std::cin >> k;
    std::cout << walk(k, 0, cost);
}
