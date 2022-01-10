#include <iostream>
#include <unordered_map>
#include <climits>

using namespace std;

int highestFrequency(int arr[], int n) {
	// Declare a unorder map
	unordered_map<int,int> frequency;

	// Declare variables maxFrequency and maxElement and initialize them with ‘0’
	int maxFrequency = 0;
	int maxElement = 0;
	for (int i = 0; i < n; ++i)
	{
		// Update the frequency of current element arr[i]
		frequency[arr[i]]++;

		// Update the maxFrequency till the current element
		maxFrequency = max( maxFrequency, frequency[arr[i]]);
	} 
	
	for (int i = 0; i < n; ++i)
	{
		// If the frequency of our current element is equal to the maxFrequency computed
		if(maxFrequency == frequency[arr[i]])
		{
			// Update the maxElement with the current element and break the loop
			maxElement = arr[i];
			break;
		}
	}
	
	return maxElement;
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << highestFrequency(arr, n);

    delete[] arr;

    return 0;
}
