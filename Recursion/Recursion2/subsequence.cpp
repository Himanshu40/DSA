#include <iostream>
#include <string>
#include <cmath>

int subsequence(std::string input, std::string output[]) {
    if (input.empty()) {
        output[0] = "";
        return 1;
    }

    std::string smallString = input.substr(1);
    int smallStringSize = subsequence(smallString, output);

    for (int i = 0; i < smallStringSize; ++i) {
        output[i + smallStringSize] = input[0] + output[i];
    }

    return 2 * smallStringSize;
}

int main() {
    std::string input;

    std::cin >> input;

    std::string *output = new std::string[(int)pow(2, input.size())];
    int count = subsequence(input, output);

    for (int i = 0; i < count; ++i) {
        std::cout << output[i] << std::endl; 
    }

    delete []output;
    return 0;
}
