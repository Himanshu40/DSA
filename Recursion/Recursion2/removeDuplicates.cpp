// Given a string S, remove consecutive duplicates from it recursively.

#include <iostream>

void removeConsecutiveDuplicates(char *input) {
    if (input[0] == '\0') {
        return;
    }

    if (input[0] == input[1]) {
        int i = 1;

        for (; input[i] != '\0'; ++i) {
            input[i - 1] = input[i];
        }

        input[i - 1] = input[i];
    
        removeConsecutiveDuplicates(input);
    }

    removeConsecutiveDuplicates(input + 1);
}

int main() {
    char s[100000];
    
    std::cin >> s;
    removeConsecutiveDuplicates(s);
    std::cout << s << std::endl;

    return 0;
}
