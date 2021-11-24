// My solution
#include <iostream>
#include <stack>

using namespace std;

int *stockSpan(int *input, int size) {
    int *output {new int[size]};
    output[0] = 1;

    if (size == 1) {
        return output;
    }

    stack<int> s;
    s.push(0);

    for (int i {1}; i < size; ++i) {
        while (input[i] > input[s.top()]) {
            s.pop();
                    
            if (s.empty()) {
                output[i] = i + 1;
                break;
            }
        }

        if (!s.empty()) {
            output[i] = i - s.top();                    
        }
        
        s.push(i);
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
