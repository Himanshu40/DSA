#include <iostream>

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int start, int end) {
    int pivot = arr[start];
    int count = 0;

    for (int i = start + 1; i < end; ++i) {
        if (pivot > arr[i]) {
            ++count;
        }
    }


    swap(arr[start], arr[start + count]);
    
    int i = start;
    int j = end;

    while (i <= j) {
        if (arr[i] < pivot) {
            i++;
        }
        else if (arr[j] >= pivot) {
            j--;
        }
        else {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    return (count + start);
}

void quickSort(int arr[], int start, int end) {
    if (start >= end) {
        return;
    }

    int pivotIndex = partition(arr, start, end);
    quickSort(arr, start, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, end);
}

void quickSort(int input[], int size) {
    quickSort(input, 0, size - 1);
}

int main(){
    int n;
    std::cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        std::cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        std::cout << input[i] << " ";
    }
    
    delete []input;

}
