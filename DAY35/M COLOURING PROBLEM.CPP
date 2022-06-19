bool is_valid(bool graph[101][101], int n, vector<int> &color, int k, int i){
    for(int j=0; j<n; j++){
        if(graph[i][j] and color[j] == k){
            return false;
        }
    }
    return true;
}


bool solve(bool graph[101][101], int m, int n, vector<int> &color, int i){
    if(i == n){
        return true;
    }
    
    for(int k=0; k<m; k++){
        if(is_valid(graph, n, color, k, i)){
            color[i] = k;
            
            if(solve(graph, m, n, color, i+1)){
                return true;
            }
            
            color[i] = -1;
        }
    }
    
    return false;
}


bool graphColoring(bool graph[101][101], int m, int n) {
    vector<int> color(n, -1);
    return solve(graph, m, n, color, 0);
}