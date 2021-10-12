// Given an array of length N and an integer x, you need to find and return the first index of integer x present in the array. 
// Return -1 if it is not present in the array.

#include <iostream>

int firstIndex(int input[], int size, int x) {
    if (size == 0) {
        return -1;
    }

    if (input[0] == x) {
        return 0;
    }

    int ans = firstIndex(input + 1, size - 1, x);

    if (ans != -1) {
        return ans + 1;
    }
    else {
        return -1;
    }
}

int main() {
    int arr1[] = {1, 2, 5};

    std::cout << firstIndex(arr1, sizeof(arr1) / sizeof(int), 51) << std::endl;

    return 0;
}
