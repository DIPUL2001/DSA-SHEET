vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int> > adj;
        for(auto &p : adjacentPairs) {
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }
        vector<int> ans(adjacentPairs.size() + 1, INT_MIN);
        unordered_map<int, int> vis;
        for(auto it : adj) {
            if(it.second.size() == 1) {
                if(ans[0] == INT_MIN) {
                    ans[0] = it.first;
                }else {
                    ans.back() = it.first;
                }
                vis[it.first] = 1;
            }
        }
        
        for(int i = 1; i < ans.size() - 1; ++i) {
            for(int x : adj[ans[i - 1]]) {
                if(vis[x]) continue;
                ans[i] = x;
                vis[x] = 1;
            }
        }
        return ans;
    }