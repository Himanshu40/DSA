#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int buyTicket(int *arr, int n, int k) {
    priority_queue<int> maxHeap;
    queue<int> pq;

    for (int i {0}; i < n; ++i) {
        maxHeap.push(arr[i]);
        pq.push(i);
    }

    int time {0};

    while (true) {
        if (maxHeap.top() == arr[pq.front()]) {
            ++time;
            maxHeap.pop();

            int temp {pq.front()};
            pq.pop();

            if (k == temp) {
                break;
            }
        }
        else {
            pq.push(pq.front());
            pq.pop();
        }
    }

    return time;
}

int main() {
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << buyTicket(arr, n, k);

    delete[] arr;

    return 0;
}
