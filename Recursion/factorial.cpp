#include <iostream>

unsigned int factorial(unsigned int n) {
    if (n == 0) {
        return 1;
    }

    return n * factorial(n - 1);
}

int main() {
    unsigned int num;

    std::cout << "Enter a number: ";
    std::cin >> num;

    std::cout << "Factorial of " << num << " = " << factorial(num) << std::endl;

    return 0;
}