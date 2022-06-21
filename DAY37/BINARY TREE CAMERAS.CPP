class Solution {
public:
   int camera(TreeNode* root){
        if (root->left==NULL && root->right==NULL){
            root->val=1;
            return 0;
        }
        int res=0,l=2,r=2;
        if (root->left){
            res += camera(root->left);
            l = root->left->val;
        }
        if (root->right){
            res += camera(root->right);
            r = root->right->val;
        }
		// children are unwatched so camera needed
        if (l==1 || r==1){
            root->val = 3;
            return (res+1);
        }
		// camera present
        if (l==3 || r==3){
            root->val = 2;
            return res;
        }
		// current node is unwatched, so it will be watched from its parent node
        root->val=1;
        return res;
    }
    
    int minCameraCover(TreeNode* root) {
        int res = camera(root);
        if (root->val == 1){
            res++;
        }
        return res;
    }
};