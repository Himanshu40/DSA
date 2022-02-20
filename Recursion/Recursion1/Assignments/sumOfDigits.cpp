// Write a recursive function that returns the sum of the digits of a given integer.

#include <iostream>

int sumOfDigits(int n) {
	if (n == 0) {
        return 0;
    }
    
    return n % 10 + sumOfDigits(n / 10);
}

int main() {
   int n;

   std::cin >> n;
   std::cout << sumOfDigits(n) << std::endl;

   return 0;
}
