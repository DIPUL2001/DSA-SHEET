#include <bits/stdc++.h>
using namespace std;
  int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum = 0;
        mp[0] = 1; // for 0 reminder.
        int currSum =0;
        int ans =0;
        int rem = 0;
        for(int i =0;i<nums.size();i++) {
            currSum +=nums[i];
            rem = currSum%k;
			//If rem is negative we can convert it into positive by adding k
			//ex. -27 = -5*5 + (-2) or -27 = -6*5 +3
            if(rem <0)
                rem+=k;
			// (sum2-sum1)%k = 0 hence sum2%k = sum1%k
            if(mp[rem]) {
                ans+= mp[rem];
            }
            mp[rem]++;
        }
        return ans;
    }