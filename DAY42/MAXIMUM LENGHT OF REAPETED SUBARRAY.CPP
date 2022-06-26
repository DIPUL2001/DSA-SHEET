class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int m = A.size(), n = B.size(), ans = 0;
        vector<int> cur(n + 1, 0);
        for (int i = 1; i <= m; i++) {
            int pre = cur[0];
            for (int j = 1; j <= n; j++) {
                int temp = cur[j];
                if (A[i - 1] == B[j - 1]) {
                    cur[j] = pre + 1;
                    ans = max(ans, cur[j]);
                } else {
                    cur[j] = 0;
                }
                pre = temp;                
            }
        }
        return ans;
    }
};