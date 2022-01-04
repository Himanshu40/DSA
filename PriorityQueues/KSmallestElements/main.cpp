#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> kSmallest(int arr[], int n, int k) {
	if (k > n) {
        return {-1};
    }

    priority_queue<int> pq;

    for (int i {0}; i < k; ++i) {
        pq.push(arr[i]);
    }

    for (int i {k}; i < n; ++i) {
        if (pq.top() > arr[i]) {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    vector<int> sElement;
    for (int i {0}; i < k; ++i) {
        sElement.push_back(pq.top());
        pq.pop();
    }

    reverse(sElement.begin(), sElement.end());

    return sElement;
}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }

    int k;
    cin >> k;

    vector<int> output = kSmallest(input, size, k);
    sort(output.begin(), output.end());

    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }

    delete[] input;

    return 0;
}
