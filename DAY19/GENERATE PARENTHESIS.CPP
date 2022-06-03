  void solve(int curropen,int currclose,int remopen,int remclose,string &output,vector<string> &result){
        //base case
        if(remopen==0 &&remclose==0){
            result.push_back(output);
            return;
        }
        //'(' iske liye kheltai hai
        if(remopen>0){
            output.push_back('(');
            solve(curropen+1,currclose,remopen-1,remclose,output,result);
            output.pop_back();
        }
        //')'iske liya kuch kartai hai
        if(remclose>0 && curropen>currclose){
            output.push_back(')');
            solve(curropen,currclose+1,remopen,remclose-1,output,result);
            output.pop_back();
        }
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string output="(";
        int curropen=1;
        int currclose=0;
        int remopen=n-1;
        int remclose=n;
        
        solve(curropen,currclose,remopen,remclose,output,result);
        return result;
    }