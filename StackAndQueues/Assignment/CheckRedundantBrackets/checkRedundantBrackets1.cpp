// Coding ninja solution
#include <iostream>
#include <stack>

using namespace std;

/*
    Time complexity: O(N)
    Space complexity: O(N)

    where N is the length of the input expression
*/

bool checkRedundantBrackets(string expression) {
    stack<char> stk;
    string operators = "+-*/";

    for (int i = 0; i < expression.length(); ++i) {
        if (expression[i] == '(' || operators.find(expression[i]) != string::npos) {
            stk.push(expression[i]);
        }
        else if (expression[i] == ')') {
            bool hasOperator = false;

            while (!stk.empty() && stk.top() != '(') {
                stk.pop();
                hasOperator = true;
            }

            if (!hasOperator) {
                return true;
            }

            if (!stk.empty()) {
                stk.pop();
            }
        }
    }
    
    return false;
}

int main() {
    string input;
    cin >> input;
    cout << ((checkRedundantBrackets(input)) ? "true" : "false");

    return 0;
}
