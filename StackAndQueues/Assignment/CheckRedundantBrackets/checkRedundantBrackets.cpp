// My solution
#include <iostream>
#include <stack>

using namespace std;

bool checkRedundantBrackets(string expression) {
    stack<char> store;
    
    for (char &x : expression) {
        if (x == ')') {
            int top {store.top()};
            store.pop();
            
            bool flag {true};
            
            while (!store.empty() && top != '(') {
                if (top == '+' || top == '-' ||
                   	top == '*' || top == '/') {
                    flag = false;
                }
                
                top = store.top();
                store.pop();
            }

            if (flag == true) {
                return true;
            }
        }
        else {
        	store.push(x);    
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
