#include <bits/stdc++.h>
using namespace std;

int minCostPathHelper(int **input, int m, int n, int i, int j, int **output) {
    if (i == m - 1 && j == n - 1) {
        return input[i][j];
    }

	if (i >= m || j >= n) {
		return INT_MAX;
	}

	// Check if ans already exists
	if (output[i][j] != -1) {
		return output[i][j];
	}

    // Move downward
    int x {minCostPathHelper(input, m, n, i + 1, j, output)};
    // Move right
    int y {minCostPathHelper(input, m , n, i, j + 1, output)};
    // Move diagonally
    int z {minCostPathHelper(input, m, n, i + 1, j + 1, output)};

    int ans {input[i][j] + min(x, min(y, z))};
	output[i][j] = ans;

	return ans;
}

int minCostPath(int **input, int m, int n) {
	int **output {new int*[m]};

	for (int i {0}; i < m; ++i) {
		output[i] = new int[n];
	}

	for (int i {0}; i < m; ++i) {
		for (int j {0}; j < n; ++j) {
			output[i][j] = -1;
		}
	}

	int result {minCostPathHelper(input, m, n, 0, 0, output)};

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