#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

#define mod 1000000007
int balancedBTs(int *arr, int h) {
    if (h <= 1) {
        return 1;
    }

    if (arr[h] != -1) {
        return arr[h];
    }

    int x {balancedBTs(arr, h - 1)};
    int y {balancedBTs(arr, h - 2)};

    int temp1 {static_cast<int>((static_cast<long>(x) * x) % mod)};
    int temp2 {static_cast<int>(((2 * static_cast<long>(x) * y) % mod))};

    arr[h] = (temp1 + temp2) % mod;

    return arr[h];
}

int balancedBTs(int h) {
    int *arr {new int[h + 1]};

    memset(arr, -1, (h + 1) * sizeof(int));

    int result {balancedBTs(arr, h)};

    delete [] arr;
    return result;
}

int main() {
    int h;
    cin >> h;

    cout << balancedBTs(h);

    return 0;
}
