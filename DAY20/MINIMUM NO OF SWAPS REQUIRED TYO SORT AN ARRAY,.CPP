int minswaps(vector<int>&nums){
    int n=nums.size();
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        v[i]={nums[i],i};
    }

    sort(v.begin(),v.end());
    int count=0;
    for(int i=0;i<n;i++){
        if(v[i].second==i)
          continue;
        else{
            count++;
            swap(v[i],v[v[i].second]);
            i--;
        }
    }
    return count;
}