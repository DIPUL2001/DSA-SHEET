  // function for finding array sum
     int arraySum (int *arr, int n)
    {
    int sum = 0;
    for (int i=0; i<n; sum+=arr[i++]);
    return sum;
    }
 
// function for finding smallest element
    int smallest (int *arr, int n)
    {
    int small = INT_MAX;
    for (int i=0; i<n; i++)
        if (arr[i] < small)
            small = arr[i];
    return small;
        }
public:
    int minMoves(vector<int>& nums) {
         // find array sum
    int sum = arraySum (nums,nums.size());
 
    // find the smallest element from array
    int small = smallest (nums, nums.size());
 
    // calculate min operation required
    int minOperation = sum - (nums.size() * small);
 
    // return result
    return minOperation;
    }