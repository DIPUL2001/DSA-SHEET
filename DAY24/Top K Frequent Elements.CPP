class Solution {
    struct node{
        int no;
        int freq;
        node(int a,int b) //Constructor for value initialization for each node
        {
            no = a;
            freq = b;
        }
    };
    struct compare {    //Maintains MAX-HEAP based on frequency
        bool operator()(node const& a, node const& b)
        {
            return a.freq < b.freq;
        }
};
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;   //Key->Number...Value->Freq
        //STEP-1: Store frequency of all elements in map
        for(int ele: nums)
            m[ele]+=1;
        
        //STEP-2: Now build a heap
        priority_queue<node,vector<node>,compare> heap; //Compare defines a max-heap based on frequency
        for(auto it: m)
            heap.push(node(it.first,it.second));
        
        vector<int> ans;    //Stores top-K elements
        //STEP-3: Pop top-k elemnts and store the numbers in ans vector
        while(k--)  
        {
            node temp = heap.top();
            heap.pop();
            ans.push_back(temp.no);
        }
        return ans;
    }
};