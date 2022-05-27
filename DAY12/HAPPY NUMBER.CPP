class Solution {
private:
    int digitSquareSum(int n){
        int temp;
        int sum=0;
        
        while(n){
             temp=n%10;
            sum+=temp*temp;
            n/=10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
          int slow, fast;
    slow = fast = n;
    do {
        slow = digitSquareSum(slow);
        fast = digitSquareSum(fast);
        fast = digitSquareSum(fast);
    } while(slow != fast);
    if (slow == 1) return 1;
    else return 0;
    }
};