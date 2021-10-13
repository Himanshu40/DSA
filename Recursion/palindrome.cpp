// Check whether a given String S is a palindrome using recursion. Return true or false.

#include <iostream>

bool compare(char *s, int start, int end) {
    if (start == end) {
        return true;
    }
    
    if (s[end] != s[start]) {
        return false;
    }
    
    if (start < end + 1) {
        return compare(s, start + 1, end - 1);
    }
    
    return true;
}

bool checkPalindrome(char *input) {
    int count = 0;

    char *temp = input;
	while (*input != '\0') {
        ++count;
        ++input;
    }

    if (count == 0 || count == 1) {
        return true;
    }     

    return compare(temp, 0, count - 1);
}

int main() {
    char input[50];
    std::cin >> input;
    
    if(checkPalindrome(input)) {
        std::cout << "true" << std::endl;
    }
    else {
        std::cout << "false" << std::endl;
    }
}
