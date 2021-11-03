#include <iostream>

using namespace std;

void swap(int &num1, int &num2) {
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void reverse(int *arr, int size, int index) {
    for (int i {0}; i < size / 2; ++i) {
        swap(arr[i + index], arr[size + index - i - 1]);
    }
}

void rotate(int *input, int d, int n) {
    reverse(input, n, 0);
    reverse(input, n - d, 0);
    reverse(input, d, n - d);
}

int main() {
	int t;
	cin >> t;
	
	while (t--) {
		int size;
		cin >> size;

		int *input = new int[size];

		for (int i = 0; i < size; ++i) {
			cin >> input[i];
		}

		int d;
		cin >> d;

		rotate(input, d, size);

		for (int i = 0; i < size; ++i) {
			cout << input[i] << " ";
		}
		
		delete[] input;
		cout << endl;
	}

	return 0;
}
