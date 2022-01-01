#include <iostream>
#include <utility>

using namespace std;

void heapSort(int arr[], int n) {
    // Build the heap
    for (int i {1}; i < n; ++i) {
        int childIndex {i};

        while (childIndex > 0) {
            int parentIndex {(childIndex - 1) / 2};
        
            if (arr[childIndex] < arr[parentIndex]) {
                swap(arr[childIndex], arr[parentIndex]);
            }
            else {
                break;
            }

            childIndex = parentIndex;
        }
    }

    // Remove the elements

    int size {n};

    while (size > 1) {
        int temp {arr[0]};

        arr[0] = arr[size - 1];
        arr[size - 1] = temp;
        --size;

        int parentIndex {0};

        int lci {2 * parentIndex + 1};
        int rci {2 * parentIndex + 2};

        while (lci < size) {
            int minIndex {parentIndex};
                    
            if (arr[minIndex] > arr[lci]) {
                minIndex = lci;
            }

            if (rci < size && arr[rci] < arr[minIndex]) {
                minIndex = rci;
            }

            if (minIndex == parentIndex) {
                break;
            }

            std::swap(arr[minIndex], arr[parentIndex]);
            parentIndex = minIndex;

            lci = 2 * parentIndex + 1;
            rci = 2 * parentIndex + 2;
        }
    }
}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    } 

    heapSort(input, size);

    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    } 

    delete[] input;
}