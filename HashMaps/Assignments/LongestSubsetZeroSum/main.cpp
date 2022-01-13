#include <iostream>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    int maxLen {0};
    int sum {0};
    unordered_map<int, int> seen;

    for (int i {0}; i < n; ++i) {
        sum += arr[i];
        
        if (arr[i] == 0 && maxLen == 0) {
            maxLen = i;
        }

        if (sum == 0) {
            maxLen = i + 1;
        }

        if (seen.count(sum) > 0) {
            maxLen = max(maxLen, i - seen[sum]);
        }
        else {
            seen[sum] = i;
        }
    }

    return maxLen;
}

int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << lengthOfLongestSubsetWithZeroSum(arr, size);

    delete[] arr;
}