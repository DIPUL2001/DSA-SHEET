#include<bits/stdc++.h>
using namespace std;
 int maxProfit(vector<int>& prices) {
        int min = INT_MAX;
        int op = 0;
        int profit = 0;
        
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < min){
                min = prices[i];
            }
            profit = prices[i] - min;
            if(op < profit){
                op = profit;
            }
        }
        return op;
    }