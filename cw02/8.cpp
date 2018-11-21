#include <iostream>
#include <cmath>

int main() {
	int a, b, n;
	std::cin >> a >> b >> n;
	
	int digit = a / b;
	std::cout << (a / b) << ",";
	
	for (int i = 0; i < n; i++) {
		a -= b * digit;
		a *= 10;
		digit = a / b;
		std::cout << digit;
	}
	
	return 0;
}