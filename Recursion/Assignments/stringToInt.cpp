// Write a recursive function to convert a given string into the number it represents.
// That is input will be a numeric string that contains only numbers. 
// You need to convert the string into corresponding integer and return the answer.

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int stringToNumber(char input[]) {
	int size = strlen(input);

    if (size <= 1) {
        return input[0] - '0';
    }

    int extractNum = input[0] - '0';

    return extractNum * pow(10, size - 1) + stringToNumber(input + 1);
}

int main() {
    char input[50];

    cin >> input;
    cout << stringToNumber(input) << endl;

    return 0;
}
