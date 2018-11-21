#include <iostream>
#include "1.h"

ulamek neg(ulamek a) {
    return { -a.l, a.m };
}

int main() {
    ulamek x1, y1, z1, x2, y2, z2;

    x1 = get();
    y1 = get();
    z1 = get();
    x2 = get();
    y2 = get();
    z2 = get();

    // x1*x + y1*y = z1
    // x2*x + y2*y = z2
    //
    // x = (z1 - y1*y) / x1
    // x2*((z1 - y1*y) / x1) + y2*y = z2
    // (x2/x1) * z1 - (x2/x1) * y1*y + y2*y = z2
    // - (x2/x1) * y1*y + y2*y = z2 - (x2/x1) * z1
    // y(-(x2/x1) * y1 + y2) = z2 - (x2/x1) * z1
    // y = (z2 - (x2/x1) * z1) / (-(x2/x1) * y1 + y2)
    
    ulamek x21 = div(x2, x1);
    ulamek y = div(sub(z2, mul(x21, z1)), add(y2, mul(y1, neg(x21))));

    ulamek x = div(sub(z1, mul(y1, y)), x1);

    std::cout << "x: ";
    print(skroc(x));
    std::cout << ", y: ";
    print(skroc(y));
}
