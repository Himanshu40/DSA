// To calculate the nth fibonacci of a number

#include <iostream>

using namespace std;

unsigned int fib(unsigned int num) {
    if (num == 0) {
        return 0;
    }

    if (num == 1) {
        return 1;
    }

    return fib(num - 1) + fib(num - 2);
}

int main() {
    int num;
    cin >> num;

    cout << fib(num) << endl;

    return 0;
}
