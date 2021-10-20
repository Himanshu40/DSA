#include <iostream>

using namespace std;

int helper(char x, string input) {
    if (input.empty()) {
        return 0;
    }

    int num = 
}

int getCodes(string input, string output[10000]) {
    if (input.empty()) {
        return 0;
    }

    int num = input[0] - '0';
    char alpha;
    if (num <= 26) {
        alpha = 'a' + num - 1;
    }

}

int main(){
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;

    return 0;
}
