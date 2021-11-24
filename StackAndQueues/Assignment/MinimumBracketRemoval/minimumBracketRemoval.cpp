// My Solution
#include <iostream>
#include <stack>

using namespace std;

int countBracketReversals(string input) {
    if (input.size() % 2) {
        return -1;
    }
    
    stack<char> s;
    
    for (auto &x : input) {
        if (x == '{') {
            s.push(x);
        }
        else {
            if (s.empty()) {
                s.push(x);
            }
            else if (!s.empty() && s.top() == '{') {
                s.pop();
            }
            else if (!s.empty() && s.top() != '{') {
                s.push(x);
            }
        }
    }

    int counter {0};
    while (!s.empty()) {
        char c1 {s.top()};
        s.pop();

        char c2 {s.top()};
        s.top();

        if (c1 == c2) {
            ++counter;
        }
        else {
            counter += 2;
        }
    }    

    return counter;
}

int main() {
    string input;
    cin >> input;

    cout << countBracketReversals(input);

    return 0;
}
