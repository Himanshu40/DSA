#include <iostream>
#include <unordered_map>

using namespace std;

void printIntersection(int arr1[], int arr2[], int n, int m) {
    unordered_map<int, int> seen;

    for (int i {0}; i < n; ++i) {
        seen[arr1[i]]++;
    }

    for (int i {0}; i < m; ++i) {
        if (seen.count(arr2[i]) > 0) {
            seen[arr2[i]]--;

            if (seen[arr2[i]] == 0) {
                seen.erase(arr2[i]);
            }

            cout << arr2[i] << endl;
        }
    }
}

int main() {
    int n;
    cin >> n;

    int* arr1 = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr1[i];
    }

    int m;
    cin >> m;

    int* arr2 = new int[m];

    for (int i = 0; i < m; ++i) {
        cin >> arr2[i];
    }

    printIntersection(arr1, arr2, n, m);

    delete[] arr1;
    delete[] arr2;

    return 0;
}
