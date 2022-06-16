class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   unordered_map<int, int> mp;
        int sum = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            sum += A[i];
            if(sum == 0){
                ans = max(ans , i + 1);
            }
            else if(!mp.count(sum)){
                mp[sum] = i;
            }
            else{
                ans = max(ans, i - mp[sum]);
            }
        }
        return ans;
    }