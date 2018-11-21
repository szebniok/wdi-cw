#include <iostream>
#include <climits>
#include <cstdint>

constexpr uint64_t pow(uint64_t n, uint64_t p) {
    uint64_t retval = n;
    while (p > 1) {
        retval *= n;
        p--;
    }
    return retval;
}

constexpr uint64_t sum_p(uint64_t n) {
    uint64_t p = 0;
    uint64_t nn = n;
    while (nn > 0) {
        p++;
        nn /= 10;
    }

    uint64_t retval = 0;
    while (n > 0) {
        uint64_t d = n % 10;
        n /= 10;
        retval += pow(d, p);
    }

    return retval;
}

int main() {
    const uint64_t SIZE = 2'050'000;
    bool primes[SIZE];
    for (uint64_t i = 2; i < SIZE; i++) {
        primes[i] = true;
    }

    uint64_t primes_count = 0;
    for (uint64_t i = 2; i < SIZE; i++) {
        if (primes[i]) {
            primes_count++;
            if (i == sum_p(i)) std::cout << i << std::endl; 

            for (uint64_t j = 2; i * j < SIZE; j++) {
                primes[i*j] = false;
            }
        }
    }

    std::cout << primes_count;
}