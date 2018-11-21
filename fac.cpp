#include <iostream>

int main() {
  unsigned long long int N = 1'000'000;
  unsigned long long int fac = 1;
  for (unsigned long long int i = 2; i <= N; i++) {
    int ii = i;
    while (ii % 2 == 0) ii /= 2;
    while (ii % 5 == 0) ii /= 5;
    fac *= ii % 10;
    /*while (fac % 10 == 0) {
      fac /= 10;
    }
    fac %= 10;*/
    //std::cout << i << std::endl;
  }

  std::cout << fac % 100000;
}
