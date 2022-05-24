TreeNode* invertTree(TreeNode* root) {
          if (!root) {
            return NULL;
        }
        queue<TreeNode*> todo;
        todo.push(root);
        while (!todo.empty()) {
            TreeNode* node = todo.front();
            todo.pop();
            swap(node -> left, node -> right);
            if (node -> left) {
                todo.push(node -> left);
            }
            if (node -> right) {
                todo.push(node -> right);
            }
        }
        return root;
    }