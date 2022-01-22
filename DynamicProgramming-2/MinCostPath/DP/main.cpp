#include <bits/stdc++.h>
using namespace std;

int minCostPath(int **input, int m, int n) {
	int **output {new int*[m]};

	for (int i {0}; i < m; ++i) {
		output[i] = new int[n];
	}

	// Fill in the last cell i.e destination
	output[m - 1][n - 1] = input[m - 1][n - 1];

	// Fill in the last row (right to left)
	for (int j {n - 2}; j >= 0; --j) {
		output[m - 1][j] = output[m - 1][j + 1] + input[m - 1][j];
	}

	// Fill last column (bottom to top)
	for (int i {m - 2}; i >= 0; --i) {
		output[i][n - 1] = output[i + 1][n - 1] + input[i][n - 1];
	}

	// Fill remaining cells
	for (int i {m - 2}; i >= 0; --i) {
		for (int j {n - 2}; j >= 0; --j) {
			output[i][j] = input[i][j] + min(output[i + 1][j], min(output[i][j + 1], output[i + 1][j + 1]));
		}
	}

	int result {output[0][0]};

	for (int i {0}; i < m; ++i) {
		delete output[i];
	}

	return result;
}

int main() {
	int **arr, n, m;
	cin >> n >> m;
	arr = new int *[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << minCostPath(arr, n, m) << endl;

    return 0;
}