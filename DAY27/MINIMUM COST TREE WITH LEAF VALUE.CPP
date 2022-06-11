  int mctFromLeafValues(vector<int>& arr) {
         int sum = 0;
       while(arr.size() > 1)
       {
           int min_product = INT_MAX;   // min(a[0]*a[1], ... a[N-1]*a[N])
           int me_index = -1;           // min(a[i], a[i+1])
           
           for(int i = 1; i < arr.size(); ++i)
           {
               if( min_product > arr[i-1]*arr[i])
               {
                   me_index = arr[i-1] < arr[i] ? i - 1 : i;
                   min_product = arr[i-1]*arr[i];
               }
           }
           sum += min_product;
           arr.erase(arr.begin() + me_index);
       }
       
       return sum;
    }