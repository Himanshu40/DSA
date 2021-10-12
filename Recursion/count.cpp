// to find out and return the number of digits present in a number recursively
#include <iostream>

int count(int n) {
    if (n == 0) {
        return 0;
    }

    return count(n / 10) + 1;
}

int main() {
    std::cout << count(142563) << std::endl;

    return 0;
}
