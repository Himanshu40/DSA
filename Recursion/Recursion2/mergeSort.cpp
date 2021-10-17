#include <iostream>

void sort(int array[], int size)  {
    int i, key, j;

    for (i = 1; i < size; i++)
    {
        key = array[i];
        j = i - 1;
 
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }

        array[j + 1] = key;
    }
}

void merge(int input[], int array1[], int array2[], int size1, int size2) {
    int totalSize = size1 + size2;
    int indexOfArray1 = 0, indexOfArray2 = 0, indexOfInput = 0;;
    
    while (indexOfArray1 < size1 && indexOfArray2 < size2) {
        if (array1[indexOfArray1] <= array2[indexOfArray2]) {
            input[indexOfInput] = array1[indexOfArray1];
            indexOfArray1++;
        }
        else {
            input[indexOfInput] = array2[indexOfArray2];
            indexOfArray2++;
        }

        indexOfInput++;
    }

    while (indexOfArray1 < size1) {
        input[indexOfInput] = array1[indexOfArray1];
        indexOfArray1++;
        indexOfInput++;
    }

    while (indexOfArray2 < size2) {
        input[indexOfInput] = array2[indexOfArray2];
        indexOfArray2++;
        indexOfInput++;
    }
}

void mergeSort(int input[], int size){
	if (size <= 1) {
        return;
    }

    int size1 = size / 2;
    int size2 = size - size1;

    int *array1 = new int[size1];
    int *array2 = new int[size2];

    for (int i = 0; i < size1; ++i) {
        array1[i] = input[i];
    }

    sort(array1, size1);

    for (int i = 0; i < size2; ++i) {
        array2[i] = input[size1 + i];
    }

    sort(array2, size2);

    merge(input, array1, array2, size1, size2);
}

int main() {
	int length;

	std::cin >> length;
	
	int* input = new int[length];
	for(int i=0; i < length; i++) {
		std::cin >> input[i];
	}
	
	mergeSort(input, length);
	
	for(int i = 0; i < length; i++) {
		std::cout << input[i] << " ";
	}

	return 0;
}
