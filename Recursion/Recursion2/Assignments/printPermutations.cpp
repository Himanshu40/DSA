#include <iostream>
#include <string>

using namespace std;

void helper(string input, string output) {
    if (input.empty()) {
        cout << output << endl;
        return;
    }

    for (int i = 0; i < input.size(); ++i) {
        helper(input.substr(0, i) + input.substr(i + 1), output + input[i]);
    }
}

void printPermutations(string input){

    /* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
    helper(input, "");
}

int main() {
    string input;
    cin >> input;
    printPermutations(input);

    return 0;
}