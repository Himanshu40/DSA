#include <bits/stdc++.h>

using namespace std;

int countMinStepsToOneHelper(int *arr, int n) {
    if (n <= 1) {
        return 0;
    }

    if (arr[n] != -1) {
        return arr[n];
    }

    int x {countMinStepsToOneHelper(arr, n - 1)};

    int y {INT_MAX};
    if (n % 2 == 0) {
        y = countMinStepsToOneHelper(arr, n / 2); 
    }

    int z {INT_MAX};
    if (n % 3 == 0) {
        z = countMinStepsToOneHelper(arr, n / 3);
    }

    int ans {min(x, min(y, z)) + 1};
    arr[n] = ans;

    return arr[n];

}

int countMinStepsToOne(int n) {
    int *arr {new int[n + 1]};

    memset(arr, -1, (n + 1) * sizeof(int));

    int result {countMinStepsToOneHelper(arr, n)};

    delete [] arr;
    return result;
}

int main() {
	int n;
	cin >> n;
	cout << countMinStepsToOne(n);
}