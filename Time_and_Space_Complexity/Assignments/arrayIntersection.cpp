#include <iostream>

using namespace std;

void merge(int array[], int const left, int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
  
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
  
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
  
    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0; 
    int indexOfMergedArray = left; 
  
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

void mergeSort(int *arr, int beg, int end) {
    if (beg >= end) {
        return;
    }
        
    int mid = beg + (end - beg) / 2;

    mergeSort(arr, beg, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, beg, mid, end);
}

void intersection(int *arr1, int *arr2, int n, int m) {
    mergeSort(arr1, 0, n - 1);
    mergeSort(arr2, 0, m - 1);

    int i {0}, j {0};

    while (i < n && j < m) {
        if (arr1[i] == arr2[j]) {
            cout << arr1[i] << " ";
            ++i;
            ++j;
        }
        else if (arr1[i] < arr2[j]) {
            ++i;
        }
        else {
            ++j;
        }
    }
}

int main() {
	int t;
	cin >> t;

	while (t--)
	{
		int size1, size2;

		cin >> size1;
		int *input1 = new int[size1];

		for (int i = 0; i < size1; i++) {
			cin >> input1[i];
		}

		cin >> size2;
		int *input2 = new int[size2];

		for (int i = 0; i < size2; i++) {
			cin >> input2[i];
		}

		intersection(input1, input2, size1, size2);
		
		delete[] input1;
		delete[] input2;
		
		cout << endl;
	}

	return 0;
}
