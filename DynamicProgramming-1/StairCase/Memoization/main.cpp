#include <iostream>
#include <cstring>

using namespace std;

long staircaseHelper(long *arr, int n) {
    if (n <= 1) {
        return 1;
    }
    else if (n == 2) {
        return 2;
    }

    if (arr[n] != -1) {
        return arr[n];
    }
    
    long x = staircaseHelper(arr, n - 1);
    long y = staircaseHelper(arr, n - 2);
    long z = staircaseHelper(arr, n - 3);

    arr[n] = x + y + z;    
    
    return arr[n];
}

long staircase(int n) {
    long *arr {new long[n + 1]};

    memset(arr, -1, (n + 1) * sizeof(long));

    int result {staircaseHelper(arr, n)};

    delete [] arr;
    return result;
}

int main()
{
	int n;
	cin >> n;
	cout << staircase(n);
}