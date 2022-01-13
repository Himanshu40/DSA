#include <iostream>
#include <unordered_map>

using namespace std;

int getPairsWithDifferenceK(int *arr, int n, int k) {
    unordered_map<int, int> seen;
    int count {0};

    for (int i {0}; i < n; ++i) {
        seen[arr[i]]++;
    }

    if (k == 0) {
        for (int i {0}; i < n; ++i) {
            if (seen[arr[i]] != 1) {
                count += seen[arr[i]] - 1;
                --seen[arr[i]];
            }
        }

        return count;
    }

    for (int i {0}; i < n; ++i) {
        if (seen.count(arr[i] + k) > 0) {
            count += (seen[arr[i]] * seen[arr[i] + k]);
        }
        
        if (seen.count(arr[i] - k) > 0) {
            count += (seen[arr[i]] * seen[arr[i] - k]);
        }

        seen.erase(arr[i]);
    }

    return count;
}

int main() {
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int k;
    cin >> k;

    cout << getPairsWithDifferenceK(input, n, k);

    delete[] input;
}