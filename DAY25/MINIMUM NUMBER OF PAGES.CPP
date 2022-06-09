class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool ispossible(int A[], int N, int M,int mid){
        int pagesum=0;
        int studcount=1;
        for(int i=0;i<N;i++){
            if(pagesum+A[i]<=mid){
                pagesum+=A[i];
            }
            else{
                studcount++;
                if(studcount>M ||A[i]>mid )
                 return false;
                 
                 pagesum=A[i];
            }
        
            
        }
        return true;
        
    }
    int findPages(int A[], int N, int M) 
    {
       int s=0;
       int sum=0;
       for(int i=0;i<N;i++){
           sum+=A[i];
       }
       int e=sum;
       int mid=s+(e-s)/2;
       int ans=0;
       while(s<=e){
           if(ispossible(A,N,M,mid)){
               ans=mid;
               e=mid-1;
           }
           else{
               s=mid+1;
           }
           mid=s+(e-s)/2;
       }
       return ans;
    }
};
