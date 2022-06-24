 int numDistinct(string s, string t) {
	//we use unsigned int because there is a case with a quite large data
        vector<vector<unsigned int>> dp(t.size() + 1, vector<unsigned int>(s.size() + 1));
        
		//set as default value of  the first line as 1
        for (int j = 0; j <= s.size(); j++)dp[0][j] = 1;

//logic of the loop is above
        for (int i = 1; i <= t.size(); i++) {
            for (int j = 1; j <= s.size(); j++) {

					if (t[i - 1] == s[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
                }
                else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
        return dp[dp.size() - 1][dp[0].size() - 1];
    }