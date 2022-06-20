// C++ program to print all palindromic partitions
// of a given string.
#include <bits/stdc++.h>
using namespace std;

// Returns true if str is palindrome, else false
bool checkPalindrome(string str)
{
	int len = str.length();
	len--;
	for (int i=0; i<len; i++)
	{
		if (str[i] != str[len])
			return false;
		len--;
	}
	return true;
}

void printSolution(vector<vector<string> > partitions)
{
	for (int i = 0; i < partitions.size(); ++i)
	{
		for(int j = 0; j < partitions[i].size(); ++j)
			cout << partitions[i][j] << " ";
		cout << endl;
	}
	return;
}

// Goes through all indexes and recursively add remaining
// partitions if current string is palindrome.
void addStrings(vector<vector<string> > &v, string &s,
				vector<string> &temp, int index)
{
	int len = s.length();
	string str;
	vector<string> current = temp;
	if (index == 0)
		temp.clear();
	for (int i = index; i < len; ++i)
	{
		str = str + s[i];
		if (checkPalindrome(str))
		{
			temp.push_back(str);
			if (i+1 < len)
				addStrings(v,s,temp,i+1);
			else
				v.push_back(temp);
			temp = current;
		}
	}
	return;
}

// Generates all palindromic partitions of 's' and
// stores the result in 'v'.
void partition(string s, vector<vector<string> >&v)
{
	vector<string> temp;
	addStrings(v, s, temp, 0);
	printSolution(v);
	return;
}

// Driver code
int main()
{
	string s = "geeks";
	vector<vector<string> > partitions;
	partition(s, partitions);
	return 0;
}
