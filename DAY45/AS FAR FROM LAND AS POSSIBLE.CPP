class Solution {
public:

    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        
        
        //pushing the 1s
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                }
            }
        }
        
        
        //performing the bfs
        int count=0;
        while(!q.empty()){
            count++;
            
            int n=q.size();
            
			//we are doing the bfs in a for loop to make it multisourced
			//in this way all the 1s would search for adjacent 0s per count++
			
            for(int i=0;i<n;i++){
			
				//taking the coordinates of each 1
                int x=q.front().first;
                int y=q.front().second;
                
                q.pop();
                
				//searching for that 1's adjacent 0s
				//if we find a 0, we mark it visited using 1 and push it in the queue for the next multisource bfs call
				
				//since there are 4 directions, there are 4 if condtions here
                if(x+1<=grid.size()-1 && grid[x+1][y]==0){
                    q.push({x+1,y});
                    grid[x+1][y]=1;
                }
                if(x-1>=0 &&grid[x-1][y]==0){
                    q.push({x-1,y});
                    grid[x-1][y]=1;
                }
                if(y+1<=grid[0].size()-1 && grid[x][y+1]==0){
                     q.push({x,y+1});
                     grid[x][y+1]=1;
                }                   
                if(y-1>=0 &&grid[x][y-1]==0){
                    q.push({x,y-1});
                    grid[x][y-1]=1;
                }
                    
            }
            
        }
        
        return count>1?count-1:-1;
        
    }
};