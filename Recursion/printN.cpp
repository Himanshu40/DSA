// to print numbers from 1 to n in increasing order recursively
#include <iostream>

void print(int n) {
    if (n == 1) {
        std::cout << n << " ";
        return;
    }

    print(n - 1);
    std::cout << n << " ";
}

int main() {
    print(6);

    return 0;
}
