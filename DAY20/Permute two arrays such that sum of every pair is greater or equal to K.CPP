  bool isPossible(long long a[], long long b[], long long n, long long k) {
       //SORT THE ARRAY  A IN ACENDING ORDER
       sort(a,a+n);
       //SORT THE ARRAY B IN DECENDING ORDER
       sort(b,b+n,greater<int>());
       
       
       for(int i=0;i<n;i++){
           if(a[i]+b[i]<k)
            return false;
            
       }
       return true;
    }