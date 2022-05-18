    bool visited[6][6];
    
    bool solve(vector<vector<char>>& board,string word,int m,int n,string s,int r,int c)
    {
        if(s==word) return true;
        if(r<0 || c<0 || r>=m || c>=n || board[r][c]!=word[s.size()] || visited[r][c]==true)
            return false;
        
        s+=board[r][c];
        visited[r][c]=true;
		int d = solve(board,word,m,n,s,r+1,c);               // Moving downward
        int u = solve(board,word,m,n,s,r-1,c);               // Moving upward
        int f = solve(board,word,m,n,s,r,c+1);               // Moving right or forward
        int b = solve(board,word,m,n,s,r,c-1);               // Moving left or backward
        visited[r][c]=false;
        s.pop_back();
        return u || d || f || b;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(),n=board[0].size();
        string s="";
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(board[i][j]==word[0])
                    if(solve(board,word,m,n,s,i,j))
                        return true;
        
        return false;
    }