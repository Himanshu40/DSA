// To calculate the sum of the array using recursion

#include <iostream>

int sumArray(int *arr, int size) {
    if (size == 1) {
        return arr[size - 1];
    }

    return arr[0] + sumArray(arr + 1, size - 1);
}

int main() {
    int arr1[] = {1, 2, 5};

    std::cout << sumArray(arr1, sizeof(arr1) / sizeof(int)) << std::endl;

    return 0;
}
