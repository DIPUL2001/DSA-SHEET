class Solution {
public:
    enum Color {WHITE, GRAY, BLACK};
    bool dfs(int i, vector<int> & color, vector<vector<int>> & graph)
    {
        if(color[i])
            return color[i] == BLACK;
        color[i] = GRAY;
        for(int & v : graph[i])
        {
            if(color[v] == GRAY)
                return false;
            if(color[v] == WHITE && !dfs(v, color, graph))
                return false;
        }
        color[i] = BLACK;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph)
    {
        int n = int(graph.size());
        vector<int> color(n, WHITE);
        vector<int> result;
        for(int i = 0; i < n; ++i)
            if(dfs(i, color, graph))
                result.push_back(i);
        return result;
    }
};