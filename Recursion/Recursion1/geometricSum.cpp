// Given k, find the geometric sum i.e. 1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^k) using recursion

#include <iostream>
#include <iomanip>

double geometricSum(int k) {
	if (k == 0) {
        return 1;
    }
    
    int temp = k;
    int result = 1;
    
    while (temp != 0) {
        result *= 2;
        temp--;
    }
    
    double store =  1 / (double)result + geometricSum(k - 1);
    
    return store;
}

int main() {
    int k;
    
    std::cin >> k;
    std::cout << std::fixed << std::setprecision(5);
    std::cout << geometricSum(k) << std::endl;   
}