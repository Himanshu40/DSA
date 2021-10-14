// Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".

#include <iostream>
#include <cstring>

void replacePi(char input[]) {
    int size = strlen(input);

	if (size < 1) {
        return;
    }

    if (input[0] == 'p' && input[1] == 'i') {
        for (int i = size; i > 1; --i) {
            input[i + 2] = input[i];
        }

        input[0] = '3';
        input[1] = '.';
        input[2] = '1';
        input[3] = '4';
    }

    replacePi(input + 1);
}

int main() {
    char input[10000];
    
    std::cin.getline(input, 10000);
    replacePi(input);
    
    std::cout << input << std::endl;

    return 0;
}

// xpixpix
// x3.14xpix\0
// x3.14x3.14x
