 int majorityElement(vector<int>& nums) {
      
         unordered_map<int,int> m;
         
        for (int i : nums) {
            if (++m[i]>nums.size() / 2) {
                return i;
            }
        }
        return 0;
    }