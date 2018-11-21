#include <iostream>

int A(int n) {
	return n * n + n + 1;
}

int main() {
	int N;
	std::cin >> N;
	
	int result = 1;
	for (int n = 2; n <= N; n++) {
		int a = n;
		while (a % 2 == 0) a /= 2;
		while (a % 3 == 0) a /= 3;
		while (a % 5 == 0) a /= 5;
		
		if (a == 1) result++;
	}
	
	std::cout << result;
	return 0;
}