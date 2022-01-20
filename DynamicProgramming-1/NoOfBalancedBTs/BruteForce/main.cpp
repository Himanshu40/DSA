#include <iostream>
#include <cmath>

using namespace std;

int balancedBTs(int h) {
    if (h <= 1) {
        return 1;
    }

    int mod {static_cast<int>(pow(10, 9) + 7)};
    int x {balancedBTs(h - 1)};
    int y {balancedBTs(h - 2)};

    int temp1 {static_cast<int>((static_cast<long>(x) * x) % mod)};
    int temp2 {static_cast<int>(((2 * static_cast<long>(x) * y) % mod))};

    int ans {(temp1 + temp2) % mod};

    return ans;
}

int main() {
    int h;
    cin >> h;

    cout << balancedBTs(h);

    return 0;
}
