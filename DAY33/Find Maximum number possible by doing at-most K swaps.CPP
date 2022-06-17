// C++ program to find maximum
// integer possible by doing
// at-most K swap operations on
// its digits.
#include <bits/stdc++.h>
using namespace std;

// Function to find maximum
// integer possible by
// doing at-most K swap operations
// on its digits
void findMaximumNum(
	string str, int k,
	string& max, int ctr)
{
	// return if no swaps left
	if (k == 0)
		return;

	int n = str.length();

	// Consider every digit after
	// the cur position
	char maxm = str[ctr];
	for (int j = ctr + 1; j < n; j++) {
		// Find maximum digit greater
		// than at ctr among rest
		if (maxm < str[j])
			maxm = str[j];
	}

	// If maxm is not equal to str[ctr],
	// decrement k
	if (maxm != str[ctr])
		--k;

	// search this maximum among the rest from behind
	//first swap the last maximum digit if it occurs more then 1 time
//example str= 1293498 and k=1 then max string is 9293418 instead of 9213498
	for (int j = n-1; j >=ctr; j--) {
		// If digit equals maxm swap
		// the digit with current
		// digit and recurse for the rest
		if (str[j] == maxm) {
			// swap str[ctr] with str[j]
			swap(str[ctr], str[j]);

			// If current num is more than
			// maximum so far
			if (str.compare(max) > 0)
				max = str;

			// recurse other swaps after cur
			findMaximumNum(str, k, max, ctr + 1);

			// Backtrack
			swap(str[ctr], str[j]);
		}
	}
}

// Driver code
int main()
{
	string str = "129814999";
	int k = 4;

	string max = str;
	findMaximumNum(str, k, max, 0);

	cout << max << endl;

	return 0;
}
