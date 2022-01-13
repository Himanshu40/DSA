#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    unordered_map<int, bool> seen;

    for (int i {0}; i < n; ++i) {
        seen[arr[i]] = false;
    }

    int maxLength {-1};
    int minIndex {INT_MAX};
    vector<int> longestSeq;

    for (int i {0}; i < n; ++i) {
        int currMaxLen {0};
        int maxNum {arr[i]};
        int minNum {arr[i]};
        int currMinIndex {i};

        for (int j {maxNum}; seen.count(j) > 0; ++j) {
            if (seen[j] == false) {
                currMaxLen++;
                seen[j] = true;
                maxNum = j;
            }
            else {
                break;
            }
        }

        for (int j {minNum - 1}; seen.count(j) > 0; --j) {
            if (seen[j] == false) {
                currMaxLen++;
                seen[j] = true;
                minNum = j;
            }
            else {
                break;
            }
        }

        if (arr[currMinIndex] != minNum) {
            for (int j {0}; j < n; ++j) {
                if (minNum == arr[j]) {
                    currMinIndex = j;
                    break;
                } 
            }
        }

        if (currMaxLen > maxLength) {
            maxLength = currMaxLen;
            minIndex = currMinIndex;

            longestSeq.clear();
            longestSeq.push_back(minNum);
            longestSeq.push_back(maxNum);
        }
        else if (currMaxLen == maxLength) {
            if (minIndex > currMinIndex) {
                minIndex = currMinIndex;

                longestSeq.clear();
                longestSeq.push_back(minNum);
                longestSeq.push_back(maxNum);
            }
        }
    }

    return longestSeq;
}

int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    vector<int> ans = longestConsecutiveIncreasingSequence(arr, size);

    for (auto i = ans.begin(); i != ans.end(); ++i)
        cout << *i << " ";

    delete[] arr;
}
