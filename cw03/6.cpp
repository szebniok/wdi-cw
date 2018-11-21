#include <iostream>

int main() {
	int numbers[10];
	
	for (int i = 0; i < 10; i++) numbers[i] = -1;
	
	while (true) {
		int N;
		std::cin >> N;
		
		if (N == 0) break;
		
		int i = 0;
		while (numbers[i] > N) { i++; }
		
		int tmp = numbers[i];
		for (int j = i; j < 9; j++) {
			int t = numbers[j + 1];
			numbers[j + 1] = tmp;
			tmp = t;
		}
		
		numbers[i] = N;
	}
	
	std::cout << "---------";
	
	for (int i = 0; i < 10; i++) std::cout << numbers[i] << " ";
	
	std::cout << std::endl;
	
	std::cout << numbers[9];
}