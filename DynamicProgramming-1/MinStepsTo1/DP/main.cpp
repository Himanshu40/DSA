#include <bits/stdc++.h>

using namespace std;

int countMinStepsToOne(int n) {
    int *arr {new int[n + 1]};

    arr[0] = 0;
    arr[1] = 0;

    for (int i {2}; i <= n; ++i) {
        arr[i] = arr[i - 1];

        if (i % 2 == 0) {
            arr[i] = min(arr[i / 2], arr[i]);
        }

        if (i % 3 == 0) {
            arr[i] = min(arr[i / 3], arr[i]);
        }
        
        arr[i] += 1;
    }

    int result {arr[n]};
    delete [] arr;

    return result;
}

int main() {
	int n;
	cin >> n;
	cout << countMinStepsToOne(n);
}