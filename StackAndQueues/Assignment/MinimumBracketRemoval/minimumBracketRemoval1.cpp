// Coding ninja solution
#include <iostream>
#include <stack>

using namespace std;

/*
    Time Complexity : O(N)
    Space Complexity : O(N)

    where N is the number of brackets
*/

int countBracketReversals(string input) {
    int len = input.length();

    if (len == 0) {
        return 0;
    }

    // Only even number of brackets can be balanced
    if (len % 2 != 0) {
        return -1;
    }
    
    stack<char> stack;
    
    for (int i = 0; i < len; i++) {
        char currentChar = input[i];

        if (currentChar == '{') {
            stack.push(currentChar);
        }
        else {
            // Pop if there is a balanced pair
            if (!stack.empty() && stack.top() == '{') {
                stack.pop();
            }
            else {
                stack.push(currentChar);
            }
        }
    }

    int count = 0;

    // Only unbalanced brackets are there in stack now
    while (!stack.empty()) {
        char char1 = stack.top();
        stack.pop();

        char char2 = stack.top();
        stack.top();

        /*
            When char1 = } and char2 = {, then we need to reverse both of them
            so count will increase by 2
        */
        if (char1 == char2) {
            count += 1;
        }
        else {
            count += 2;
        }
    }    

    return count;
}

int main() {
    string input;
    cin >> input;

    cout << countBracketReversals(input);

    return 0;
}
