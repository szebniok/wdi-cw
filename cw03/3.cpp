#include <iostream>

int main() {
	int N;
	std::cin >> N;
	
	bool is_prime[N];
	for (int i = 2; i < N; i++) is_prime[i] = true;
	
	
	for (int i = 2; i < N; i++) {
		if (is_prime[i]) {
			for (int j = 2; i * j < N; j++) 
				is_prime[i * j] = false;
		}
	}
	
	for (int i = 2; i < N; i++) if (is_prime[i]) std::cout << i << std::endl;
}