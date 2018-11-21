#include <iostream>
#include <cmath>

int main() {
	const int N = 5;
	
	int result[N];
	for (int i = 0; i < N; i++) result[i] = 0;
	
	int factorial[N];
	for (int i = 0; i < N - 1; i++) factorial[i] = 0;
	factorial[N - 1] = 1;
	
	for (int b = 1; b <= N; b++) {
		int b_digits[N];
		for (int k = 0; k < N; k++) b_digits[k] = 0;
		int ii = N - 1;
		int bb = b;
		while (bb > 0) {
			b_digits[ii--] = bb % 10;
			bb /= 10;
		}
		
		int new_factorial[N];
		for (int i = 0; i < N; i++) new_factorial[i] = 0;
		int offset = 0;
		while (b_digits[N - 1] > 0) {
			int carry = 0;
			for (int i = N - 1; i >= 0; i--) {				
				int calc = b_digits[N - 1] * factorial[i] + carry;
				int digit = calc % 10;
				new_factorial[i - offset] += digit;
				carry = calc / 10;
				carry += new_factorial[i - offset] / 10;
				new_factorial[i - offset] %= 10;
			}
			offset++;
			int tmp = b_digits[0];
			for (int i = 0; i < N - 1; i++) {
				int t = b_digits[i + 1];
				b_digits[i + 1] = tmp;
				tmp = t;
			}
			int jj = -1;
			while (b_digits[++jj] == 0) ;
			b_digits[jj] = 0;
		}
		
		for (int i = 0; i < N; i++) factorial[i] = new_factorial[i];
		
		// odwracanie
		
		`
	}
	
	for (int i = 0; i < N; i++) std::cout << factorial[i];
	
	std::cout << std::endl;
	
	
	std::cout << result[0] << ",";
	for (int i = 1; i < N; i++) {
		std::cout << result[i];
	}
}