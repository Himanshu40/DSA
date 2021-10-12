// To check if an array is sorted or not using recursion

#include <iostream>

bool isSorted(const int *arr, int size) {
    if (size == 0 || size == 1) {
        return true;
    }

    if (arr[0] > arr[1]) {
        return false;
    }

    return isSorted(arr + 1, size - 1);
}

int main() {
    int arr1[] = {1, 2, 5, 7, 9};

    std::cout << std::boolalpha << isSorted(arr1, sizeof(arr1) / sizeof(int)) << std::endl;

    int arr2[] = {1, 2, 8, 5, 7, 9};

    std::cout << std::boolalpha << isSorted(arr2, sizeof(arr2) / sizeof(int)) << std::endl;

    return 0;
}
