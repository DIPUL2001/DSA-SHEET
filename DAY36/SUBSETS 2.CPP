class Solution {
    void helper(vector<vector<int>>& res, vector<int>& temp, vector<int>& nums, int pos){
        res.push_back(temp);
        
        for(int i=pos; i<nums.size(); ++i){
            if(i != pos && nums[i] == nums[i - 1]) continue;
            temp.push_back(nums[i]);
            helper(res, temp, nums, i + 1);
            temp.pop_back();
            
        }
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        helper(res, temp, nums, 0);
        return res;
    }
};