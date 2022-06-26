int longestCommonSubstr (string s1, string s2, int n, int m)
   {
       int dp[n+1][m+1];
       for(int i=0; i<n+1; i++) {
           for(int j=0; j<m+1; j++) {
               if(i==0 || j==0) {
                   dp[i][j] = 0;
               }
               else {
                   break;
               }
           }
       }
       int maxi = 0;
       for(int i=1; i<n+1; i++) {
           for(int j=1; j<m+1; j++) {
               if(s1[i-1] == s2[j-1]) {
                   dp[i][j] = 1 + dp[i-1][j-1];
                   maxi = max(maxi, dp[i][j]);
               }
               else {
                   dp[i][j] = 0;
               }
           }
       }
       return maxi;
   }