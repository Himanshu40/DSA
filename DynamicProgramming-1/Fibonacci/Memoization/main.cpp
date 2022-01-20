#include <iostream>
#include <cstring>

using namespace std;

int fibHelper(int *ans, int n) {
    if (n <= 1) {
        return n;
    }

    // Check if output already exists
    if (ans[n] != -1) {
        return ans[n];
    }

    int a {fibHelper(ans, n - 1)};
    int b {fibHelper(ans, n - 2)};

    // save the output for future use
    ans[n] = a + b;

    return ans[n];
}

int fib(int n) {
    int *ans {new int[n + 1]};
    memset(ans, -1, (n + 1) * sizeof(int));

    int result {fibHelper(ans, n)};

    delete [] ans;
    return result;
}

int main() {
    int n;
    cin >> n;

    cout << fib(n) << endl;

    return 0;
}