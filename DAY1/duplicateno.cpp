#include<bits/stdc++.h>
using namespace std;


// using linked list and slow and fast pointer approach
int duplicates(vector<int> nums){
    int slow=nums[0];
       int fast=nums[0];
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);
        
            fast=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
}
