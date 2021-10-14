// Tower Of Hanoi

#include <iostream>

void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 0) {
        return;
    }

	if (n == 1) {
        std::cout << n << " " << source << " " << destination << std::endl;
        return;
    }
    
    towerOfHanoi(n - 1, source, destination, auxiliary);
    std::cout << n << " " << source << " " << destination << std::endl;
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n;

    std::cin >> n;
    towerOfHanoi(n, 'a', 'b', 'c');

    return 0;
}
