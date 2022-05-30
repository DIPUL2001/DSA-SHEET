// C++ program to find minimum cost to
// make all elements equal
#include <bits/stdc++.h>
using namespace std;

// Utility method to compute cost, when
// all values of array are made equal to X
int computeCost(int arr[], int N, int X)
{
	int cost = 0;
	for (int i = 0; i < N; i++)
		cost += abs(arr[i] - X);
	return cost;
}

// Method to find minimum cost to make all
// elements equal
int minCostToMakeElementEqual(int arr[], int N)
{
	int low, high;
	low = high = arr[0];

	// setting limits for ternary search by
	// smallest and largest element
	for (int i = 0; i < N; i++) {
		if (low > arr[i])
			low = arr[i];
		if (high < arr[i])
			high = arr[i];
	}

	/* loop until difference between low and high
	become less than 3, because after that
	mid1 and mid2 will start repeating
	*/
	while ((high - low) > 2) {

		// mid1 and mid2 are representative array
		// equal values of search space
		int mid1 = low + (high - low) / 3;
		int mid2 = high - (high - low) / 3;

		int cost1 = computeCost(arr, N, mid1);
		int cost2 = computeCost(arr, N, mid2);

		// if mid2 point gives more total cost,
		// skip third part
		if (cost1 < cost2)
			high = mid2;

		// if mid1 point gives more total cost,
		// skip first part
		else
			low = mid1;
	}

	// computeCost gets optimum cost by sending
	// average of low and high as X
	return computeCost(arr, N, (low + high) / 2);
}

// Driver code to test above method
int main()
{
	int arr[] = { 1, 100, 101 };
	int N = sizeof(arr) / sizeof(int);
	cout << minCostToMakeElementEqual(arr, N);
	return 0;
}
