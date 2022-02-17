// Given two integers M & N, calculate and return their multiplication using recursion. 
// You can only use subtraction and addition for your calculation. No other operators are allowed.

#include <iostream>

int multiplyNumbers(int m, int n) {
	if (n == 1) {
        return m;
    }
    
    return m + multiplyNumbers(m, n - 1);
}

int main() {
    std::cout << multiplyNumbers(5, 2) << std::endl;

    return 0;
}
