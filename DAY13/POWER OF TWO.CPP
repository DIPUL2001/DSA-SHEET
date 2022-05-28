  bool isPowerOfTwo(int n) {
  /* THIS SOUTION IS A BASIC ONE 
//         if(n<=0) return false;
        
//       return (n&(n-1)==0);\
*/        
        
        //setbit
        if(n<=0)
          return false;
        
        int count=0;
        while(n!=0)
        {
            if(n&1)
                count++;
            n=n>>1;
        }
        if(count>1)return false;
        
        return true;
        
 }