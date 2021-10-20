#include <iostream>

using namespace std;

void helper(int input[], int size1, int output[], int size2) {
    if (size1 == 0) {
        for (int i = 0; i < size2 - 1; ++i) {
            cout << output[i] << " ";
        }
        cout << endl;

        return;
    }

    int *store = new int[size2];

    int i = 0;
    for (; i < size2 - 1; i++) {
        store[i] = output[i];
    }

    store[i] = input[0];

    helper(input + 1, size1 - 1, store, size2 + 1);
    helper(input + 1, size1 - 1, store, size2);

    delete []store;
}

void printSubsetsOfArray(int input[], int size) {
    if (size == 1 || size == 0) {
        cout << input[0] << std::endl;

        return;
    }

    int *output = new int[0];

	helper(input, size, output, 1);

    delete []output;
}

int main() {
    int input[1000],length;
    cin >> length;

    for(int i=0; i < length; i++)
        cin >> input[i];
    
    printSubsetsOfArray(input, length);

    return 0;
}
