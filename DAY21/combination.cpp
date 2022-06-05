class Solution {
public:
    
    
    void helper(int idx, int k,vector<int>&current,int n, vector<vector<int>>& ans)
    {
        if(current.size()==k)    // base case
        {
            ans.push_back(current);
            return;
        }
        
        for(int i=idx;i<n+1;i++)
        {
            current.push_back(i);  //consider the current element i
            helper(i+1,k,current,n,ans); // generate combinations
            current.pop_back(); //proceed to next element
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int>current;
        helper(1,k,current,n,ans);
        return ans; //return answer
    }
};