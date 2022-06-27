vector<int> bfsOfGraph(int V, vector<int> adj[]) {
       vector<int> ans;
       queue<int> q;
       vector<bool> visited;
       visited.resize(V,false);
       //pushing or starting with initial element
       q.push(0);
       visited[0];
       while(!q.empty())
       {
           int s=q.front();
           ans.push_back(s);
           q.pop();
           for(auto adjacent:adj[s])
           {
               while(!visited[adjacent])
               {
                   //check if not coming again
                   visited[adjacent]=true;
                   q.push(adjacent);
               }
           }
       }
         
       return ans;
   }