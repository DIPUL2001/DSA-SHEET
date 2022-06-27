bool isCycle(int V, vector<int> adj[]) {
       // Code here
       int visited[V];
       memset(visited,0,sizeof(visited));
       queue<int> q;
       for(int i=0;i<V;i++)
       {
           if(visited[i]==0)
           {
               q.push(i);
               while(!q.empty())
               {
                   int k = q.front();
                   q.pop();
                   if(visited[k]==0)
                   {
                       visited[k]=1;
                       for(auto itr:adj[k])
                       {
                           if(visited[itr]==0)
                           q.push(itr);
                       }
                   }
                   else
                   {
                       return true;
                   }
               }
           }
       }
       return false;
   }