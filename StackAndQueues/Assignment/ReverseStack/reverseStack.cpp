// My solution
#include <iostream>
#include <stack>

using namespace std;

void reverseStack(stack<int> &input, stack<int> &extra) {
    if (input.size() <= 1) {
        return;
    }

    while (!input.empty()) {
        int x {input.top()};
        
        extra.push(x);
        input.pop();        
    }
    
    input = extra;
}

int main() {
    stack<int> input, extra;
    int size;
    cin >> size;

    for (int i = 0, val; i < size; i++) {
        cin >> val;
        input.push(val);
    }

    reverseStack(input, extra);

    while (!input.empty()) {
        cout << input.top() << " ";
        input.pop();
    }

    return 0;
}
