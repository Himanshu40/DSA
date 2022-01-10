#include <iostream>
#include <unordered_map>

using namespace std;

int pairSum(int *arr, int n) {
    unordered_map<int, int> seen;
    int count {0};

    for (int i {0}; i < n; ++i) {
        if (arr[i] < 0 || arr[i] > 0) {
            if (seen.count(arr[i] * -1) > 0) {
                if (seen[arr[i] * -1] > 0) {
                    count += seen[arr[i] * -1];
                }
            }
        }
        else {
            if (seen.count(arr[i]) > 0) {
                if (seen[arr[i]] > 0) {
                    count += seen[arr[i]];
                }
            }
        }

        seen[arr[i]]++;
    }

    return count; 
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << pairSum(arr, n);

    delete[] arr;

    return 0;
}
