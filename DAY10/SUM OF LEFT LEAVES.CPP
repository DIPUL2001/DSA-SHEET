 int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root, false);
    }
    int dfs(TreeNode* root, bool isLeft) {
        if(!root) return 0;
        if(!root -> left && !root -> right) return isLeft ? root -> val : 0;
        return dfs(root -> left, true) + dfs(root -> right, false);
    }