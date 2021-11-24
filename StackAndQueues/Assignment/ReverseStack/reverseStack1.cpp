// Coding ninja solution
#include <iostream>
#include <stack>

using namespace std;

/*
    Time Complexity: O(N^2)
    Space Complexity: O(N^2)

    where N is the size of the input stack
*/

void reverseStack(stack<int> &input, stack<int> &extra) {
    if (input.size() <= 1) {
        return;
    }

    int lastElement = input.top();
    input.top();

    reverseStack(input, extra);

    while (!input.empty()) {
        int top = input.top();

        input.pop();
        extra.push(top);
    }

    input.push(lastElement);

    while (!extra.empty()) {
        int top = extra.top();

        extra.pop();
        input.push(top);
    }
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
