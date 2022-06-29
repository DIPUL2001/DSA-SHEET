class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        // support variables declared here
		int res = 0, len, currCumulatedTime, currNode;
        pair<int, int> currNodeInfo;
        // getting the graph in a more navigable format
        vector<vector<int>> paths(n);
        for (int id = 0; id < n; id++) if (id != headID) paths[manager[id]].push_back(id);
        // preparing layers for a BFS approach to be in the <cumulated time, id> format
        queue<pair<int, int>> layer;
        layer.push({0, headID});
        while (layer.size()) {
            len = layer.size();
            for (int i = 0; i < len; i++) {
                // extracting the stored node information
                currNodeInfo = layer.front();
                currCumulatedTime = currNodeInfo.first;
                currNode = currNodeInfo.second;
                // adding more nodes to be connected if this is not a terminal one
                if (paths[currNode].size()) {
                    for (auto node: paths[currNode]) layer.push({currCumulatedTime + informTime[currNode], node});
                }
                // else updating res
                else res = max(currCumulatedTime, res);
                // removing the parsed node from the queue
                layer.pop();
            }
        }
        return res;
    }
};
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        // support variables declared here
		int res = 0, len, currCumulatedTime, currNode;
        pair<int, int> currNodeInfo;
        // getting the graph in a more navigable format
        vector<vector<int>> paths(n);
        for (int id = 0; id < n; id++) if (id != headID) paths[manager[id]].push_back(id);
        // preparing layers for a BFS approach to be in the <cumulated time, id> format
        queue<pair<int, int>> layer;
        layer.push({0, headID});
        while (layer.size()) {
            len = layer.size();
            for (int i = 0; i < len; i++) {
                // extracting the stored node information
                currNodeInfo = layer.front();
                currCumulatedTime = currNodeInfo.first;
                currNode = currNodeInfo.second;
                // adding more nodes to be connected if this is not a terminal one
                if (paths[currNode].size()) {
                    for (auto node: paths[currNode]) layer.push({currCumulatedTime + informTime[currNode], node});
                }
                // else updating res
                else res = max(currCumulatedTime, res);
                // removing the parsed node from the queue
                layer.pop();
            }
        }
        return res;
    }
};
