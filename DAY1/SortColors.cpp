#include<bits/stdc++.h>
using namespace std;
// using 3 pointers low,mid,high putting at specific position
void sortcolors(vector<int>& nums,int n){
    int l=nums[0],m=nums[0],h=nums[n-1];
    while(m<=h){
     if(nums[m]==0){
         swap(nums[l],nums[m]);
         l++;
         m++;
     }
     if(nums[m]==1)
       m++;
     if(nums[m]==2){
        swap(nums[m],nums[h]);
        h--;
    }
    }
}

