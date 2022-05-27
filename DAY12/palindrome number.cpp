 bool isPalindrome(int x) {
        int digit;
        long reverse=0;
        int temp=x;
        while(x>0){
             
         digit=x%10;
         reverse=(reverse*10)+digit;
         x=x/10;
            
        }
        if(reverse==temp){
            return true;
        }
        else{
            return false;
        }
    }