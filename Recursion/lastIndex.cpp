// Given an array of length N and an integer x, you need to find and return the last index of integer x present in the array. 
// Return -1 if it is not present in the array.
// Last index means - if x is present multiple times in the array, return the index at which x comes last in the array.

#include <iostream>

int lastIndex(int input[], int size, int x) {
    if (size == 0) {
        return -1;
    }

    int ans = lastIndex(input + 1, size - 1, x);

    if (ans != -1) {
        return ans + 1;
    }
    
    if (input[0] == x) {
        return 0;
    }
    else {
        return -1;
    }
}

int main() {
    int arr1[] = {1, 2, 5, 2, 4, 2, 5};

    std::cout << lastIndex(arr1, sizeof(arr1) / sizeof(int), 2) << std::endl;

    return 0;
}
