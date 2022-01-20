#include <iostream>
#include <cstring>

using namespace std;

int fib(int n) {
    if (n <= 1) {
        return n;
    }

    int a {fib(n - 1)};
    int b {fib(n - 2)};

    return a + b;
}

int main() {
    int n;
    cin >> n;

    cout << fib(n) << endl;

    return 0;
}