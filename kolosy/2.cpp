#include <iostream>

const int N = 11;

int max(int t[N]);

int main() {
    int t[N] = {1, 3, 1, 2, 1, 15, 15, 15, 15, 15, 1};
    
    int result = max(t);
    std::cout << "max: " << result;
}
    
int max(int t[N]) {
    int retval = 0; 

    for (int i = 0; i < N; i++) {
        int left = i;
        int current_length = 0;
        for (int right = N - 1; right >= i; right--) {
            bool is_even = t[left] % 2 == 0 || t[right] % 2 == 0;
            bool not_equal = t[left] != t[right];

            
            
            /*
            
            std::cout << "left: " << left << ", right: " << right << ", length: " << current_length;
            std::cout << ", is_even" << is_even << ", not_equal " << not_equal;
            char c; std::cin >> c;
            */
            
           
            if (is_even || not_equal) {
                left = i;
                current_length = 0;
                continue;
            }

            if (left == right) {
                if (current_length * 2 + 1 > retval)
                    retval = current_length * 2 + 1;

                break;
            }

            current_length++;

            if (left == right - 1) {
                if (current_length * 2 > retval)
                    retval = current_length * 2;

                break;
            }
            
            left++;
        }
    }

    return retval;
}
