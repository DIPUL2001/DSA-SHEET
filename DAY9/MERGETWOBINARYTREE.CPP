 TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
         if ( root1 && root2 ) {
            TreeNode * root = new TreeNode(root1->val + root2->val);
            root->left = mergeTrees(root1->left, root2->left);
            root->right = mergeTrees(root1->right, root2->right);
            return root;
        } else {
            return root1 ? root1 : root2;
        }
    }