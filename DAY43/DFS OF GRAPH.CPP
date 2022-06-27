class Solution {
 public:
   void dfsUtility(int i,vector<int> adj[],vector<int> &ans,vector<int> &vis){
        ans.push_back(i);
        vis[i] = 1;
        for(auto it : adj[i]){
            if(!vis[it]) dfsUtility(it,adj,ans,vis);
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<int> vis(V,0);
        dfsUtility(0,adj,ans,vis);
        return ans;
    }
};