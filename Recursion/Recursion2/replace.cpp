// Given an input string S and two characters c1 and c2, you need to replace every occurrence of character c1 with character c2 in the given string.

#include <iostream>

using namespace std;

void replaceCharacter(char input[], char c1, char c2) {
    if (input[0] == '\0') {
        return;
    }

    if (input[0] == c1) {
        input[0] = c2;
    }

    replaceCharacter(input + 1, c1, c2);
}

int main() {
    char input[1000000];
    char c1, c2;

    cin >> input;
    cin >> c1 >> c2;
    
    replaceCharacter(input, c1, c2);
    
    cout << input << endl;

    return 0;
}
