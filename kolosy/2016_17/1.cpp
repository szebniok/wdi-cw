#include <iostream>
#include <cstdlib>
#include <ctime>

const int MAX = 10;

int main() {
    srand(time(NULL));
    int tab[MAX];

    for (int i = 0; i < MAX; i++) 
        tab[i] = rand() % 900 + 100;

    for (int i = 0; i < MAX; i++) 
        std::cout << tab[i] << " ";
}
