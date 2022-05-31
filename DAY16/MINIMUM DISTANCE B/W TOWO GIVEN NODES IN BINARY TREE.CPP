class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
     Node* lca(Node* root,int a,int b){
       if(root==NULL) return NULL;
       if(root->data==a||root->data==b) return root;
       Node* left=lca(root->left,a,b);
       Node* right=lca(root->right,a,b);
       if(!left) return right;
       if(!right) return left;
       return root;
   }
   int distance(Node* root,int num,int dist){
       if(root==NULL) return -1;
       if(root->data==num) return dist;
       int left=distance(root->left,num,dist+1);
       if(left!=-1) return left;
       return distance(root->right,num,dist+1);
   }
   int findDist(Node* root, int a, int b) {
       // Your code here
       Node* lowest=lca(root,a,b);
       // cout<<lowest->data<<endl;
       return distance(lowest,a,0)+distance(lowest,b,0);
   }
};