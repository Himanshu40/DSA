#include <iostream>

unsigned int power(unsigned int base, unsigned int exp) {
    if (exp == 0) {
        return 1;
    }

    return base * power(base, exp - 1);
}

int main() {
    unsigned int base, exp;

    std::cout << "Enter base: ";
    std::cin >> base;

    std::cout << "Enter power: ";
    std::cin >> exp;

    std::cout << base << " ^ " << exp << " = " << power(base, exp) << std::endl;

    return 0;
}
