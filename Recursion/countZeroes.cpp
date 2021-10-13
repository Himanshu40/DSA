// Given an integer N, count and return the number of zeros that are present in the given integer using recursion.

#include <iostream>

int countZeros(int n) {
    // Write your code here
	if (n / 10 == 0) {
        if (n == 0) {
            return 1;
        }
        return 0;
    }
    
    if (n % 10 == 0) {
        return countZeros(n / 10) + 1;
    }
    else {
        return countZeros(n / 10);
    }
}

int main() {
    int n;
    
    std::cin >> n;
    std::cout << countZeros(n) << std::endl;

    return 0;
}