bool isCyclic(int V, vector<int> adj[]) 
 {
     vector<int>indegree(V,0);
     queue<int>q;
     
     for(int i=0;i<V;i++)
     {
         for(auto j:adj[i])
             indegree[j]++;
     }
     
     for(int i=0;i<V;i++)
     {
         if(indegree[i]==0)
         q.push(i);
     }
     int count=0;
     while(!q.empty())
     {
         int node=q.front();
         q.pop();
         count++;  // extra variable to check whether number of nodes in queue is equal to given number of nodes, if yes then it indicates that it will have topological sort then we conclude that this graph doesn't have cycle
         
         for(auto it:adj[node])
            {
                indegree[it]--;
                
                if(indegree[it]==0)
                q.push(it);
            }
     }
     if(count==V)
        return false;
     
     return true;
   
 }