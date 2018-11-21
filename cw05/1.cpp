#include <iostream>
#include "1.h"

int nwd(int a, int b) {
    return (b == 0) ? a : nwd(b, a % b);
}

ulamek add(ulamek a, ulamek b) {
    return ulamek { a.l * b.m + b.l * a . m, a.m * b.m };
}

ulamek sub(ulamek a, ulamek b) {
    return add(a, ulamek { - b.l, b.m });
}

ulamek mul(ulamek a, ulamek b) {
    return ulamek { a.l * b.l, b.m * a.m };
}

ulamek div(ulamek a, ulamek b) {
    return mul(a, ulamek { b.m, b.l });
}

ulamek skroc(ulamek a) {
    int n = nwd(a.l, a.m);
    return ulamek { a.l / n, a.m / n };
}

ulamek pow(ulamek a, int n) {
    if (n == 1) return a;
    
    if (n % 2 == 0) return pow(mul(a, a), n / 2);

    return mul(a, pow(a, n - 1));
}

void print(ulamek a) {
    std::cout << "[" << a.l << " / " << a.m << "]";
}

ulamek get() {
    int l, m;
    std::cin >> l >> m;
    return ulamek { l, m };
}

/*int main() {
    ulamek u1 = ulamek { 1, 2 };
    ulamek u2 = ulamek { 3, 4 };

    print(skroc(add(u1, mul(u1, u2))));
    std::cout << " ";
    print(pow(u1, 10));
}*/
