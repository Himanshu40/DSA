#include <iostream>

using namespace std;

int findDuplicate(int *arr, int n)
{
    int sum1 {0};

    for (int i {0}; i < n; ++i) {
        sum1 += arr[i];
    }

    int sum2 = ((n - 2) * (n - 1)) / 2;

    return sum1 - sum2;
}

int main()
{
	int t;
	cin >> t;
	
	while (t--)
	{
		int size;
		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cout << findDuplicate(input, size) << endl;
	}

	return 0;
}
