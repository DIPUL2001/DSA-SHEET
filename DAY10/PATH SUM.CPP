 bool hasPathSum(TreeNode* root, int targetSum) {
           if(!root)return false;                                         //Terminating Condition
       targetSum=targetSum-root->val;                                             //Body
        if(targetSum==0&&!root->left&&!root->right)return true;              //body
        return hasPathSum(root->left,targetSum)||hasPathSum(root->right,targetSum);//Propagation
    }