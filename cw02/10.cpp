#include <iostream>
#include <cmath>

int main() {
	int k;
	std::cin >> k;
	
	int n = 1;
	double result = -1, prev;
	
	const double EPSILON = 0.000001;
	
	do {
		prev = result;
		result = 0;
		
		double delta = (k - 1) / double(n);
		
		double x = 1;
		for (int i = 0; i < n; i++) {
			result += (1 / (x + i * delta)) * delta;
		}
		
		n++;
	} while (fabs(result - prev) > EPSILON);
	
	std::cout << result;;
	return 1;
}