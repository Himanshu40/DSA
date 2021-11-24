#include <iostream>
#include <string>
#include <stack>

bool isBalanced(std::string expression) {
    if (expression.empty()) {
        return false;
    }

    if (expression[0] == ')' || expression[0] == '}' || expression[0] == ']') {
        return false;
    }

    std::stack<char> s1;

    for (char &i : expression) {
        if (i == '{' || i == '(' || i == '[') {
            s1.push(i);
            continue;
        }

        if (i == ')' || i == '}' || i == ']') {
            char store {s1.top()};

            if (store == '{' && i == '}') {
                s1.pop();
            }
            else if (store == '(' && i == ')') {
                s1.pop();
            }
            else if (store == '[' && i == ']') {
                s1.pop();
            }
            else {
                return false;
            }
        }
    }

    if (s1.empty()) {
        return true;
    }

    return false;
}

int main() {
    std::string input;
    std::cin >> input;
    
    std::cout << ((isBalanced(input)) ? "true" : "false");

    return 0;
}
