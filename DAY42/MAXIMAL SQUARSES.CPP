class Solution {
public:
    int maximalSquare(vector<vector<char>>& M) {
        int m = size(M), n = size(M[0]), ans = 0;
        vector<vector<int>> dp(2, vector<int>(n+1));
        for(int i = m-1; ~i; i--)
            for(int j = n-1; ~j; j--) 
                dp[i&1][j] = (M[i][j] == '1' ? 1 + min({dp[(i+1)&1][j], dp[i&1][j+1], dp[(i+1)&1][j+1]}) : 0),
                ans = max(ans, dp[i&1][j]);

        return ans * ans;
    }
};