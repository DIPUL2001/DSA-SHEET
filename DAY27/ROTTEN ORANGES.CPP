 int orangesRotting(vector<vector<int>>& grid) {
        // Code here
          if(grid.size()==0)
        return 0;
        int tot=0,cnt=0;
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]!=0)tot++;
                if(grid[i][j]==2)q.push({i,j});
            }
        }
        int xarr[4]={0,0,1,-1};
        int yarr[4]={1,-1,0,0};
        int n=grid.size();
        int m=grid[0].size();
        int day=0;
        while(!q.empty()){
            int k=q.size();
            cnt+=k;
            while(k--){
            int x=q.front().first,y=q.front().second;   
            q.pop();
                for(int i=0;i<4;i++){
                int nx=x+xarr[i],ny=y+yarr[i];
                if(nx<0||ny<0||nx>=n||ny>=m||grid[nx][ny]!=1)continue;
                grid[nx][ny]=2;
                q.push({nx,ny});
                    
                }
            }
            if(!q.empty())day++;
            
        }
        
      return (cnt==tot)?day:-1;  
        
    }