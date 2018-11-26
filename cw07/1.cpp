/*
 * Problem skoczka szachowego
 */

#include <iostream>
#include <climits>

const int N = 7;

bool isValidMove(int x, int y) {
    return x >= 0 && x <= N - 1 && y >= 0 && y <= N - 1;
}

bool loop(int x, int y, bool taken[N][N], int moves) {
    if (moves == N * N) {
        std::cout << y << " " << x << std::endl;
        return true;
    }

    taken[y][x] = true;

    int newX, newY;

    newX = x - 1;
    newY = y - 2;
    if (isValidMove(newY, newX) && !taken[newY][newX]) {
        if (loop(newX, newY, taken, moves + 1)) {
            std::cout << y << " " << x << std::endl;
            return true;
        }
    }
    //std::cout << newX << " " << newY;

    newX = x + 1;
    newY = y - 2;
    if (isValidMove(newY, newX) && !taken[newY][newX]) {
        if (loop(newX, newY, taken, moves + 1)) {
            std::cout << y << " " << x << std::endl;
            return true;
        }
    }


    newX = x + 2;
    newY = y - 1;
    if (isValidMove(newY, newX) && !taken[newY][newX]) {
        if (loop(newX, newY, taken, moves + 1)) {
            std::cout << y << " " << x << std::endl;
            return true;
        }
    }

    newX = x + 2;
    newY = y + 1;
    if (isValidMove(newY, newX) && !taken[newY][newX]) {
        if (loop(newX, newY, taken, moves + 1)) {
            std::cout << y << " " << x << std::endl;
            return true;
        }
    }

    newX = x + 1;
    newY = y + 2;
    if (isValidMove(newY, newX) && !taken[newY][newX]) {
        if (loop(newX, newY, taken, moves + 1)) {
            std::cout << y << " " << x << std::endl;
            return true;
        }
    }

    newX = x - 1;
    newY = y + 2;
    if (isValidMove(newY, newX) && !taken[newY][newX]) {
        if (loop(newX, newY, taken, moves + 1)) {
            std::cout << y << " " << x << std::endl;
            return true;
        }
    }

    newX = x - 2;
    newY = y + 1;
    if (isValidMove(newY, newX) && !taken[newY][newX]) {
        if (loop(newX, newY, taken, moves + 1)) {
            std::cout << y << " " << x << std::endl;
            return true;
        }
    }

    newX = x - 2;
    newY = y - 1;
    if (isValidMove(newY, newX) && !taken[newY][newX]) {
        if (loop(newX, newY, taken, moves + 1)) {
            std::cout << y << " " << x << std::endl;
            return true;
        }
    }

    taken[y][x] = false;
    return false;
}

void knight() {
    bool taken[N][N] = {};
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (loop(x, y, taken, 1)) return;
        }
    }
}



int main() {
    knight();
}
