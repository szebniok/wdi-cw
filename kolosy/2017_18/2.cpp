#include <iostream>

const int N = 11;

int length(int t[N]) {
    int result = 0;
    
    for (int i = 0; i < N; i++) {
        if (t[i] % 2 == 0) continue;

        int l = i, r;
        int curr = 1;

        for (r = N - 1; r > l; r--) {
            if (t[l] == t[r] && t[l] % 2 == 1) {
                curr = (curr == 1) ? 2 : curr + 2;
                l++;
            }
            else {
                curr = 1;
                l = i;
            }
        }

        if (r == l && l > i) curr += 1;

        if (curr > result) result = curr;
    }
    return result;
}

int main() {
    int t[N] = {1, 3, 1, 2, 1, 15, 15, 15, 15, 15, 1};

    int r = length(t);
    std::cout << r;
}
