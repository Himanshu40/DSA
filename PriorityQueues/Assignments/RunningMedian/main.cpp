#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void findMedian(int *arr, int n) {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    maxHeap.push(arr[0]);
    cout << maxHeap.top() << " ";

    for (int i {1}; i < n; ++i) {
        if (arr[i] < maxHeap.top()) {
            maxHeap.push(arr[i]);
        }
        else {
            minHeap.push(arr[i]);
        }

        if (maxHeap.size() - minHeap.size() > 1) {
            int max {maxHeap.top()};

            maxHeap.pop();
            minHeap.push(max);
        }
        else if (minHeap.size() - maxHeap.size() > 1) {
            int min {minHeap.top()};

            minHeap.pop();
            maxHeap.push(min);
        }

        int c {maxHeap.size() + minHeap.size()};
        
        if(c % 2 == 0) {
            cout << (maxHeap.top() + minHeap.top()) / 2 << " ";
        }
        else {
            if(maxHeap.size() > minHeap.size()) {
                cout << maxHeap.top() << " ";
            }
            else {
                cout << minHeap.top() << " ";
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    findMedian(arr,n);

    delete[] arr;
}
