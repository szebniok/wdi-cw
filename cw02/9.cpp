#include <iostream>



int main() {
	int N;
	std::cin >> N;
	
	int a = 0, b = 1;
	
	int sum = 0;
	while (b < N) {
		sum += a;
		int tmp = b;
		b = a + b;
		a = tmp;
	}
	
	std::cout << sum;
}