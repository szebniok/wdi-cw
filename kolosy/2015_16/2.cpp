#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(NULL));
    const int N = 3;
    int t[N];
    for (int i = 0; i < N; i++) t[i] = (rand() % 49) * 2 + 1;

    int max_plus = 1, max_minus = 1;
    int curr = 2;
    int r = t[1] - t[0];
    for (int i = 1; i < N - 1; i++) {
        int newR = t[i + 1] - t[i];
        if (newR == r) {
            curr++;
            continue;
        }

        if (r > 0 && curr > max_plus) max_plus = curr;
        if (r < 0 && curr > max_minus) max_minus = curr;

        curr = 2;
        r = newR;
    }

    std::cout << "MAX+: " << max_plus << ", MAX-: " << max_minus << ", result: " << max_plus - max_minus << std::endl;

    for (int i = 0; i < N; i++) std::cout << t[i] << " ";
}
