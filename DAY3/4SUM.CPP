vector<vector<int>> fourSum(vector<int>& nums, int target) {
       vector<vector<int> > res;
    
        if (nums.empty())
            return res;
    
        std::sort(nums.begin(),nums.end());
    
        for (int i = 0; i < nums.size(); i++) {
        
            int target_3 = target - nums[i];
        
            for (int j = i + 1; j < nums.size(); j++) {
            
                int target_2 = target_3 - nums[j];
            
                int front = j + 1;
                int back = nums.size() - 1;
            
                while(front < back) {
                
                    int two_sum = nums[front] + nums[back];
                
                    if (two_sum < target_2) front++;
                
                    else if (two_sum > target_2) back--;
                
                    else {
                    
                        vector<int> quadruplet(4, 0);
                        quadruplet[0] = nums[i];
                        quadruplet[1] = nums[j];
                        quadruplet[2] = nums[front];
                        quadruplet[3] = nums[back];
                        res.push_back(quadruplet);
                    
                        // Processing the duplicates of number 3
                        while (front < back && nums[front] == quadruplet[2]) ++front;
                    
                        // Processing the duplicates of number 4
                        while (front < back && nums[back] == quadruplet[3]) --back;
                
                    }
                }
                
                // Processing the duplicates of number 2
                while(j + 1 < nums.size() && nums[j + 1] == nums[j]) ++j;
            }
        
            // Processing the duplicates of number 1
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) ++i;
        
        }
    
        return res;
    
    }