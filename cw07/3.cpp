/* Dana jest tablica int t[N]. Proszę napisać funkcję, która znajdzie niepusty,
 * najmniejszy (w sensie liczebności) podzbiór elementów tablicy, dla którego suma
 * elementów jest równa sumie indeksów tych elementów. Do funkcji należy przekazać
 * tablicę, funkcja powinna zwrócić sumę elementów znalezionego podzbioru. Na przykład
 * dla tablicy: [ 1, 7, 3, 5, 11, 2 ] rozwiązaniem jest liczba 10.
 */

#include <iostream>

const int N = 6;

struct min_sum_retval {
    int sum;
    int len;
};

min_sum_retval min_sum(const int t[N], int i = 0, int accIndex = 0, int accValue = 0, int len = 0) {
    if (len != 0 && accIndex == accValue) return { accValue, len };
    if (i == N) return (len != 0 && accIndex == accValue) 
        ? (min_sum_retval { accValue, len }) 
        : (min_sum_retval { -1, -1 });
    if (t[i] == i) min_sum_retval { i, 1 };
    
    min_sum_retval including = min_sum(t, i + 1, accIndex + i, accValue + t[i], len + 1);
    min_sum_retval notIncluding = min_sum(t, i + 1, accIndex, accValue, len);
    if (including.len == -1 && notIncluding.len == -1) return { -1, -1 };
    if (including.len == -1) return notIncluding;
    if (notIncluding.len == -1) return including;
    if (including.len < notIncluding.len) return including;
    return notIncluding;
}

int main() {
    int t[N] = {1, 7, 3, 5, 11, 2};
    min_sum_retval min = min_sum(t);
    std::cout << min.len << " " << min.sum;
}
