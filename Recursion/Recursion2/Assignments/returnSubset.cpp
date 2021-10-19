#include <iostream>

using namespace std;

int subset(int input[], int n, int output[][20]) {
    if (n == 0) {
        output[0][0] = 0;
        return 1;
    }

    int store = subset(input + 1, n - 1, output);

    for (int i = 0; i < store; ++i) {
        int noOfColoumns = output[i][0];

        output[i + store][0] = 1 + noOfColoumns;
        output[i + store][1] = input[0];
        ++noOfColoumns;

        for (int j = 1; j < noOfColoumns; ++j) {
            output[i + store][j + 1] = output[i][j];
        }
    }

    return 2 * store;
}

int main() {
    int input[20], length, output[3500][20];
    
    cin >> length;
    for(int i=0; i < length; i++)
        cin >> input[i];
    
    int size = subset(input, length, output);

    for( int i = 0; i < size; i++) { 
        for( int j = 1; j <= output[i][0]; j++) { 
            cout << output[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

// {1, 2}, ""

// (0,0) 0
// (1,0) 1 (1,1) 1
// (2,0) 1 (2,1) 2
// (3,0) 2 (3,1) 1 (3,2) 2














