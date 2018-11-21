#include <iostream>
#include <cmath>

int main() {
	int N;
	std::cin >> N;
	
	for (int i = sqrt(N); i > 0; i--) {
		if (N % i == 0) {
			std::cout << i << " * " << (N / i);
			return 0;
		}
	}
	
	std::cout << "NIE";
	return 1;
}