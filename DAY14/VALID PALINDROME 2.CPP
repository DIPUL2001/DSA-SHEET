class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size();
        if(n<=2) return true;
        
        // Keep two pointers Left and Right
        int L,R;    
        L = 0;
        R = n-1;
        
        while(L<=R)
        {
            //Both first and last element match
            if(s[L]==s[R])
            {
                ++L;--R;
            }
            
            // One of the element is not matching
            else 
            {
                //Removing Left
                int LL = L+1, LR = R;
                while(LL<=LR && s[LL]==s[LR]) {++LL;--LR;}
                if(LL>=LR) return true;
                
                //Removing Right
                int RL = L, RR = R-1;
                while(RL<=RR && s[RL]==s[RR]) {++RL;--RR;}
                if(RL>=RR) return true;

                return false;

            }
 
        }
        
     return true;   
    }  
};