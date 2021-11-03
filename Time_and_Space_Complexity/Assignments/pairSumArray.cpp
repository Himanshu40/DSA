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

int pairSum(int *arr, int n, int num) {
    mergeSort(arr, 0, n - 1);

    int start {0}, end {n - 1};
    int count {0};

    while (start <= end) {
        int sum = arr[start] + arr[end];

        if (sum == num) {
            if (arr[start + 1] == arr[start] || arr[end - 1] == arr[end]) {
                const int x {arr[start]};
                const int y {arr[end]};

                int countX {0};
                int countY {0};

                for (int i {start + 1}; arr[i] == x; ++i) {
                    ++countX;
                }

                if (start + countX + 1 == n) {
                    count += countX;
                    ++start;
                    continue;
                }

                for (int i {end - 1}; arr[i] == y; --i) {
                    ++countY; 
                }

                if (countX > 0 && countY > 0) {
                    count += ((countX + 1) * (countY + 1));
                }
                else if (countY > 0) {
                    count += countY + 1; 
                }
                else {
                    count += countX + 1;
                }

                start += (countX + 1);
                end -= (countY + 1);
            }
            else {
                ++count;
                ++start;
                --end;
            }
        }
        else if (sum > num) {
            --end;
        }
        else {
            ++start;
        }
    }

    return count;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int size;
		int x;

		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cin >> x;

		cout << pairSum(input, size, x) << endl;

		delete[] input;
	}
	
	return 0;
}
