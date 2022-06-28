 bool check(int i, int j, int N, vector<vector<int>> &dis) {
        if (i > N || i < 1 || j > N || j < 1 || dis[i][j] != -1)
            return false;
        return true;
    }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    int x[8] = {-1, 1, 2, -2, -1, 1, 2, -2};
	    int y[8] = {2, 2, 1, 1, -2, -2, -1, -1};
	    queue<vector<int>> q;
	    vector<vector<int>> dis(N + 1, vector<int>(N + 1, -1));
	    q.push(KnightPos);
	    dis[KnightPos[0]][KnightPos[1]] = 0;
	    while (!q.empty()) {
	        vector<int> u = q.front();
	        q.pop();
	        for (int v = 0; v < 8; v++) {
	            int i = u[0] + x[v];
	            int j = u[1] + y[v];
	            if (check(i, j, N, dis)) {
	                dis[i][j] = dis[u[0]][u[1]] + 1;
	                q.push({i, j});
	            }
	            if (i == TargetPos[0] && j == TargetPos[1])
	                break;
	        }
	    }
	    return dis[TargetPos[0]][TargetPos[1]];
	}