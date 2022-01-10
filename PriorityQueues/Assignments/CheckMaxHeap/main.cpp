#include <iostream>

using namespace std;

bool isMaxHeap(int arr[], int n) {
    for (int i {0}; i < n; ++i) {
        int lci {2 * i + 1};
        int rci {2 * i + 2};    

        if (lci < n) {
            if (rci < n && (arr[i] > arr[lci] && arr[i] > arr[rci])) {}
            else if (arr[i] > arr[lci]) {}
            else {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << (isMaxHeap(arr, n) ? "true\n" : "false\n");

    delete[] arr;
}