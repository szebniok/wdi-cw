#include <iostream>

int main() {
    const int N = 5;
    int numbers[5];

    //poczatek
    for (int i = 0; i < N; i++)
        std::cin >> numbers[i];

    // 0-ty element
    double s = numbers[1] + numbers[2] + numbers[3] + numbers[4];
    if (numbers[0] == s / 4) std::cout << numbers[0] << " ";
    
    // 1-ty element
    s -= numbers[1];
    s += numbers[0];
    if (numbers[1] == s / 4) std::cout << numbers[1] << " ";

    std::cout << "a";

    int n;
    while (true) {
        std::cin >> n;
        if (n == 0) break;


        for (int i = 0; i < N - 1; i++) 
            numbers[i] = numbers[i+1];

        numbers[N - 1] = n;
        
        s = numbers[0] + numbers[1] + numbers[3] + numbers[4];

        if (numbers[2] == s / 4) std::cout << numbers[2] << " ";
    } 

    std::cout << "b";

    if (numbers[2] == s / 4) std::cout << numbers[2] << " ";

    // koniec
    s = numbers[0] + numbers[1] + numbers[2] + numbers[4];
    if (numbers[3] == s / 4) std::cout << numbers[3] << " ";

    s -= numbers[0];
    s += numbers[3];
    if (numbers[4] == s / 4) std::cout << numbers[4] << " ";
}


bool pierwsza(int n) {
    if (n == 1) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i < n; i+=6) {
        if (n % i == 0 || n % (i + 2) == 0) return true;
    }
    return false;
}
