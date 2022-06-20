class Solution {   
public:
    void solve(vector<int> ans,int index,int &count){
        if(index==ans.size()){
            count++;
            return;
        }
        for(int j=index;j<ans.size();j++){
            if(ans[j]%(index+1)==0 || (index+1)%ans[j]==0){
                
                swap(ans[index],ans[j]);
                solve(ans,index+1,count);
                swap(ans[j],ans[index]);
            }
        }
   
    }
    int countArrangement(int n) {
        vector<int> ans;
        int count=0;
        for(int i=1;i<=n;i++){
            ans.push_back(i);
        }
        solve(ans,0,count);
        return count;
    }
};