#include <bits/stdc++.h>
using namespace std;

int minCostPath(int **input, int m, int n, int i, int j) {
    if (i == m - 1 && j == n - 1) {
        return input[i][j];
    }

	if (i >= m || j >= n) {
		return INT_MAX;
	}

    // Move downward
    int x {minCostPath(input, m, n, i + 1, j)};
    // Move right
    int y {minCostPath(input, m , n, i, j + 1)};
    // Move diagonally
    int z {minCostPath(input, m, n, i + 1, j + 1)};

    return input[i][j] + min(x, min(y, z));
}

int minCostPath(int **input, int m, int n) {
    return minCostPath(input, m, n, 0, 0);
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