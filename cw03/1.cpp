#include <iostream>
#include <string>

int main() {
	int N;
	std::cin >> N;
	
	int num_of_digits = 0;
	for (int tmp = N; tmp > 0; tmp /= 10) num_of_digits++;
	num_of_digits *= 4;
	
	
	char digits[num_of_digits];
	const std::string CHARS = "0123456789ABCDEF";
	
	for (int base = 2; base <= 16; base++) {
		std::cout << base << ": ";		
		for (int i = 0; i < num_of_digits; i++) digits[i] = '\0';
		
		int i = 0;
		int cpy = N;
		while (cpy > 0) {
			digits[num_of_digits - 1 - i++] = CHARS[cpy % base];
			cpy /= base;
		}
		
		for (int j = 0; j < num_of_digits; j++) {
			if (digits[j] != '\0')
				std::cout << digits[j];
		}
		std::cout << std::endl;
	}
}