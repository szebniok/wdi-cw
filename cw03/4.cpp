#include <iostream>

int main() {
	int N;
	std::cin >> N;
	
	int digits[3000];
	
	for (int i = 0; i < 3000; i++) digits[i] = 0;
	digits[2999] = 1;
	
	for (int i = 1; i <= N; i++) {
		int offset = 0;
		int b = i;
		int new_digits[3000];
		for (int j = 0; j < 3000; j++) new_digits[j] = 0;
		while (b > 0) {
			int carry = 0;
			for (int j = 2999; j >= 0; j--) {
				int calc = (b % 10) * digits[j] + carry;
				int digit = calc % 10;
				new_digits[j - offset] += digit;
				carry = calc / 10;
				carry += new_digits[j - offset] / 10;
				new_digits[j - offset] %= 10;
			}
			offset++;
			b /= 10;
		}
		for (int j = 0; j < 3000; j++) digits[j] = new_digits[j];
	}
	
	int i = -1;
	while (digits[++i] == 0) ;
	for ( ; i < 3000; i++) std::cout << digits[i];
}