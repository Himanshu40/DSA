#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

#define mod 1000000007
int balancedBTs(int h) {
    int *arr {new int[h + 1]};
    
    arr[0] = 1;
    arr[1] = 1;

    for (int i {2}; i <= h; ++i) {
        int temp1 {static_cast<int>((static_cast<long>(arr[i - 1]) * arr[i - 1]) % mod)};
        int temp2 {static_cast<int>(((2 * static_cast<long>(arr[i - 1]) * arr[i - 2]) % mod))};

        arr[i] = (temp1 + temp2) % mod;
    }

    int result {arr[h]};

    delete [] arr;

    return result;
}

int main() {
    int h;
    cin >> h;

    cout << balancedBTs(h);

    return 0;
}
