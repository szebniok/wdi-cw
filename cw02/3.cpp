#include <iostream>

int dec2bin(int n) {
	if (n < 2) return n;
	
	int digit = n % 2;
	
	return dec2bin(n/2) * 10 + digit;
}

int main() {
	int N;
	std::cin >> N;
	
	int tmp = N;
	int revN = 0;
	
	while (tmp != 0) {
		int q = tmp % 10;
		revN = revN * 10 + q;
		tmp /= 10;
	}
	
	std::cout << (revN == N ? "TAK (10)" : "NIE (10)") << std::endl;
	
	int N2 = dec2bin(N);
	
	int revN2 = 0;
	tmp = N2;
	while (tmp != 0) {
		int q = tmp % 10;
		revN2 = revN2 * 10 + q;
		tmp /= 10;
	}
		
	std::cout << (revN2 == N2 ? "TAK (2)" : "NIE (2)") << std::endl;
	
	std::cout << N2 << " " << revN2 << std::endl;
	
	std::cout << dec2bin(N);
	
	return 1;
}