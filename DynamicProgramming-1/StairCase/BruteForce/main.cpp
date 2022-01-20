#include <iostream>
using namespace std;

long staircase(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    else if (n == 2) {
        return 2;
    }
    
    long x = staircase(n - 1);
    long y = staircase(n - 2);
    long z = staircase(n - 3);    
    
    return x + y + z;
}

int main()
{
	int n;
	cin >> n;
	cout << staircase(n);
}