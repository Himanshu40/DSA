// Coding ninja solution
#include <iostream>
#include <stack>

using namespace std;

/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    where N is the number of days
*/

int *stockSpan(int *input, int size) {
    stack<int> stack;
    int *output = new int[size];

    stack.push(0);
    output[0] = 1;

    for (int i = 1; i < size; ++i) {
        while (!stack.empty() && input[stack.top()] < input[i]) {
            stack.pop();
        }

        if (stack.empty()) {
            output[i] = i + 1;
        }
        else {
            output[i] = i - stack.top();
        }

        stack.push(i);
    }

    return output;
}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }

    int *output = stockSpan(input, size);
    for (int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }

    cout << "\n";

    delete[] input;
    delete[] output;

    return 0;
}
