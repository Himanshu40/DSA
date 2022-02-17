//  Sum of Array
// Given an array of length N, you need to find and return the sum of all elements of the array.
// Do this recursively.
// Input Format :

// Line 1 : An Integer N i.e. size of array
// Line 2 : N integers which are elements of the array, separated by spaces

// Output Format :

// Sum

// Constraints :

// 1 <= N <= 10^3

// Sample Input 1 :

// 3
// 9 8 9

// Sample Output 1 :

// 26

// Sample Input 2 :

// 3
// 4 2 1

// Sample Output 2 :

// 7    

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
