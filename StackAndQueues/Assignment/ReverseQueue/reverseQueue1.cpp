// Coding Ninjas Solution
#include <iostream>
#include <queue>

using namespace std;

/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    where N is the size of the input queue
*/

void reverseQueue(queue<int> &input) {
	if (input.size() <= 1) {
        return;
    }

    int front = input.front();
    input.pop();

    reverseQueue(input);

    input.push(front);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        queue<int> q;
        int size;
        cin >> size;

        for (int i = 0, val; i < size; i++) {
            cin >> val;
            q.push(val);
        }

        reverseQueue(q);
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }

        cout << "\n";
    }

    return 0;
}
