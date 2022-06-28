class Solution {
    vector<int>parent;
    int find(int x) {
        return (parent[x] == x) ? x : find(parent[x]);
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        int c = connections.size();
        if (n-1 > c) return -1;
        
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
        
        for (int i = 0; i < c; i++) {
            int x = find(connections[i][0]);
            int y = find(connections[i][1]);
            if (x != y) parent[y] = x;
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (parent[i] == i)
                ans++;
        
        return ans-1;
    }
};