class Solution {
    vector<vector<int> > mat;
    vector<vector<int> > vis;
    int m,n;
    int x[4]={-1,0,1,0};
    int y[4]={0,1,0,-1};
    queue<pair<int,int> > que;
public:
    void dfs(int i,int j){
        vis[i][j]=1;
        que.push({i,j});
        for(int dir=0;dir<4;dir++){
            int xd=i+x[dir];
            int yd=j+y[dir];
            if(xd>=0 && yd>=0 && xd<=m-1 && yd<=n-1){
                if(!vis[xd][yd] && mat[xd][yd]==1){
                    dfs(xd,yd);
                }
            }
        }
    }
    int shortestBridge(vector<vector<int>>& A) {
        m=A.size();
        if(m==0) return 0;
        n=A[0].size();
        cout<<m<<" "<<n;
        mat=A;
        vis.resize(m,vector<int>(n,0));
        int flag=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    dfs(i,j);
                    flag=1;
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        int l=0;
        while(!que.empty()){
            int len=que.size();
            l++;
            while(len--){
                pair<int,int> poi=que.front();
                que.pop();
                vis[poi.first][poi.second]=1;
                for(int dir=0;dir<4;dir++){
                    int xd=poi.first+x[dir];
                    int yd=poi.second+y[dir];
                    if(xd>=0 && yd>=0 && xd<=m-1 && yd<=n-1){
                       if(!vis[xd][yd] && mat[xd][yd]==1){
                           return l-1;
                       }
                       else if(!vis[xd][yd] && mat[xd][yd]==0){
                           vis[xd][yd]=1;
                           que.push({xd,yd});
                       }
                    }
                }
            }
        }
        return -1;
    }
};      