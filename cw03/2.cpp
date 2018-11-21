#include <iostream>

int main() {
	int digits[10];
	for (int i = 0; i < 10; i++) {
		digits[i] = 0;
	}
	
	int N;
	std::cin >> N;
	
	while (N > 0) {
		digits[N % 10]++;
		N /= 10;
	}
	
	int M;
	std::cin >> M;
	
	while (M > 0) {
		digits[M % 10]--;
		M /= 10;
	}
	
	for (int i = 0; i < 10; i++) {
		if (digits[i] != 0) {
			std::cout << "NIE";
			return 1;
		}
	}
	
	std::cout << "TAK";
	return 0;
	
}