// To check if a number is present in an array

#include <iostream>

bool checkNum(int *arr, int size, int n) {
    if (size == 0) {
        return false;
    }
    
    if (arr[0] == n) {
        return true;
    }

    return checkNum(arr + 1, size - 1, n);
}

int main() {
    int arr1[] = {1, 2, 5};
    
    std::cout << std::boolalpha << checkNum(arr1, sizeof(arr1) / sizeof(int), 51) << std::endl;

    return 0;
}
