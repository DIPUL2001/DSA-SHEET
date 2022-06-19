// A naive method to find maximum of
// minimum of all windows of different
// sizes
#include <bits/stdc++.h>
using namespace std;

void printMaxOfMin(int arr[], int n)
{
	// Consider all windows of different
	// sizes starting from size 1
	for (int k = 1; k <= n; k++) {
		// Initialize max of min for
		// current window size k
		int maxOfMin = INT_MIN;

		// Traverse through all windows
		// of current size k
		for (int i = 0; i <= n - k; i++) {
			// Find minimum of current window
			int min = arr[i];
			for (int j = 1; j < k; j++) {
				if (arr[i + j] < min)
					min = arr[i + j];
			}

			// Update maxOfMin if required
			if (min > maxOfMin)
				maxOfMin = min;
		}

		// Print max of min for current
		// window size
		cout << maxOfMin << " ";
	}
}

// Driver program
int main()
{
	int arr[] = { 10, 20, 30, 50, 10, 70, 30 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printMaxOfMin(arr, n);
	return 0;
}
