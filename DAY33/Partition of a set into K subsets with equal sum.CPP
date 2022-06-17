// C++ program to check whether an array can be
// partitioned into K subsets of equal sum
#include <bits/stdc++.h>
using namespace std;

// Recursive Utility method to check K equal sum
// subsetition of array
/**
	array		 - given input array
	subsetSum array - sum to store each subset of the array
	taken		 - boolean array to check whether element
					is taken into sum partition or not
	K			 - number of partitions needed
	N			 - total number of element in array
	curIdx		 - current subsetSum index
	limitIdx	 - lastIdx from where array element should
					be taken */
bool isKPartitionPossibleRec(int arr[], int subsetSum[], bool taken[],
				int subset, int K, int N, int curIdx, int limitIdx)
{
	if (subsetSum[curIdx] == subset)
	{
		/* current index (K - 2) represents (K - 1) subsets of equal
			sum last partition will already remain with sum 'subset'*/
		if (curIdx == K - 2)
			return true;

		// recursive call for next subsetition
		return isKPartitionPossibleRec(arr, subsetSum, taken, subset,
											K, N, curIdx + 1, N - 1);
	}

	// start from limitIdx and include elements into current partition
	for (int i = limitIdx; i >= 0; i--)
	{
		// if already taken, continue
		if (taken[i])
			continue;
		int tmp = subsetSum[curIdx] + arr[i];

		// if temp is less than subset then only include the element
		// and call recursively
		if (tmp <= subset)
		{
			// mark the element and include into current partition sum
			taken[i] = true;
			subsetSum[curIdx] += arr[i];
			bool nxt = isKPartitionPossibleRec(arr, subsetSum, taken,
											subset, K, N, curIdx, i - 1);

			// after recursive call unmark the element and remove from
			// subsetition sum
			taken[i] = false;
			subsetSum[curIdx] -= arr[i];
			if (nxt)
				return true;
		}
	}
	return false;
}

// Method returns true if arr can be partitioned into K subsets
// with equal sum
bool isKPartitionPossible(int arr[], int N, int K)
{
	// If K is 1, then complete array will be our answer
	if (K == 1)
		return true;

	// If total number of partitions are more than N, then
	// division is not possible
	if (N < K)
		return false;

	// if array sum is not divisible by K then we can't divide
	// array into K partitions
	int sum = 0;
	for (int i = 0; i < N; i++)
		sum += arr[i];
	if (sum % K != 0)
		return false;

	// the sum of each subset should be subset (= sum / K)
	int subset = sum / K;
	int subsetSum[K];
	bool taken[N];

	// Initialize sum of each subset from 0
	for (int i = 0; i < K; i++)
		subsetSum[i] = 0;

	// mark all elements as not taken
	for (int i = 0; i < N; i++)
		taken[i] = false;

	// initialize first subset sum as last element of
	// array and mark that as taken
	subsetSum[0] = arr[N - 1];
	taken[N - 1] = true;

	// call recursive method to check K-substitution condition
	return isKPartitionPossibleRec(arr, subsetSum, taken,
									subset, K, N, 0, N - 1);
}

// Driver code to test above methods
int main()
{
	int arr[] = {2, 1, 4, 5, 3, 3};
	int N = sizeof(arr) / sizeof(arr[0]);
	int K = 3;

	if (isKPartitionPossible(arr, N, K))
		cout << "Partitions into equal sum is possible.\n";
	else
		cout << "Partitions into equal sum is not possible.\n";
}
