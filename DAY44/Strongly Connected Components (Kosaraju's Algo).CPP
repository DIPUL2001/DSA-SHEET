class Solution
{
public:
//Function to find number of strongly connected components in the graph.
// steps :
//1. find order of nodes according to their finishing time i.e.find topological sort in stack
//2. transpose the graph..i.e. reverse their direction of edges.
//3. now find of those pushed nodes which are in stack according to that order only and count component
void tp(int i, vector<int> adj[], vector<int>&vis, stack<int>&s )
{
    vis[i]=1;
    
    for(auto it:adj[i])
    {
        if(vis[it]==0)
        {
           tp(it,adj,vis,s);
        }
        
        
    }
    s.push(i);
    //return;
}
void dfs(int i, vector<int>&visited, vector<int> nadj[])
{
    visited[i]=1;
    
    for(auto it: nadj[i])
    {
        if(visited[it]==0)
        {
            dfs(it,visited, nadj);
        }
    }
}
   int kosaraju(int V, vector<int> adj[])
   {
       stack<int>s;
       s.push(0);
       //vector<int>topo;
       vector<int>vis(V,0);
       
       
       for(int i=0;i<V;i++)
       {
           if(vis[i]==0)
           {
               tp(i,adj,vis,s);
           }
       }
       
       vector<int> nadj[V];
       
       for(int i=0;i<V;i++)
       {
           for(auto it: adj[i])
           {
               nadj[it].push_back(i);
           }
       }
       vector<int>visited(V,0);
       int count=0;
       while(!s.empty())
       {
           int i=s.top();
           s.pop();
           if(visited[i]==0)
           {
               dfs(i, visited, nadj);
               count++;
           }
       }
       return count;
   }
};