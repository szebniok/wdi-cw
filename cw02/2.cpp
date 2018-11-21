#include <iostream>

int A(int n) {
	return n * n + n + 1;
}

int main() {
	int N;
	std::cin >> N;
	
	int n = 1;
	int wyr = A(n);
	
	while (wyr <= N) {
		int i;
		
		for (i = 1; i * wyr <= N; i++) ;
		
		if ((i - 1) * wyr == N || wyr == N ) {
			std::cout << (i - 1) << " * " << "A(" << n << ")";
			return 0;
		}
		
	
		wyr = A(++n);
	}
	
	std::cout << "NIE";
	
	return 1;
}