//  Check Number

// Given an array of length N and an integer x, you need to find if x is present in the array or not. Return true or false.
// Do this recursively.
// Input Format :

// Line 1 : An Integer N i.e. size of array
// Line 2 : N integers which are elements of the array, separated by spaces
// Line 3 : Integer x

// Output Format :

// 'true' or 'false'

// Constraints :

// 1 <= N <= 10^3

// Sample Input 1 :

// 3
// 9 8 10
// 8

// Sample Output 1 :

// true

// Sample Input 2 :

// 3
// 9 8 10
// 2

// Sample Output 2 :

// false

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
