#include <iostream>
#include <cmath>

int main() {
	int N;
	std::cin >> N;
	
	int a = 1, b = 1;
	
	bool czyIloczyn = false;
	
	while (a <= sqrt(N) && !czyIloczyn) {
		int c = a, d = b;
		
		//std::cout << a;
		
		while (a * c < N) {
			int tmp = d;
			d = c + d;
			c = tmp;
		}
		
		if (a * c == N) {
			std::cout << a << " * " << c;
			czyIloczyn = true;
		}
		
		int tmp = b;
		b = a + b;
		a = tmp;
	}
	
	if (!czyIloczyn) std::cout << "NIE";
}