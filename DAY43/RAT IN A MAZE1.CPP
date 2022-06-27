class Solution{
    public:
    
       int n;
    vector <string> ans;
    vector <vector<int>> maze;
    void dfs(int i, int j, string a, char ch){
        if(i == n - 1 && j == n - 1){
            ans.push_back(a);
            return;
        }
        maze[i][j] = -1;
        if(j + 1 < n && maze[i][j + 1] == 1 && ch != 'L') dfs(i, j + 1, a + 'R', 'R');
        if(i + 1 < n && maze[i + 1][j] == 1 && ch != 'U') dfs(i + 1, j, a + 'D', 'D');
        if(i - 1 >= 0 && maze[i - 1][j] == 1 && ch != 'D') dfs(i - 1, j, a + 'U', 'U');
        if(j - 1 >= 0 && maze[i][j - 1] == 1 && ch != 'R') dfs(i, j - 1, a + 'L', 'L');
        maze[i][j] = 1;
    }
    vector<string> findPath(vector<vector<int>> &m, int nn) {
        if(m[0][0] == 0) return ans; n = nn; maze = m;
        dfs(0, 0, "", 'A');
        return ans;
    }
    
};