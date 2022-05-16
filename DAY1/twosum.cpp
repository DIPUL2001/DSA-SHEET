#include<bits/stdc++.h>
using namespace std;
 vector<int> twoSum(vector<int>& nums, int target) {
  unordered_map<int, int> hash;
	vector<int> result;
	for (int i = 0; i < nums.size(); i++) {
		int numberToFind = target - nums[i];

            //if numberToFind is found in map, return them
		if (hash.find(numberToFind) != hash.end()) {
                    //+1 because indices are NOT zero based
			result.push_back(hash[numberToFind] );
			result.push_back(i );			
			return result;
		}

            //number was not found. Put it in the map.
		hash[nums[i]] = i;
	}
	return result;

    }
