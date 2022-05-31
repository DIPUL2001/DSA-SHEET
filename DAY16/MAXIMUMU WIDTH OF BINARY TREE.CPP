class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
          if(!root) return 0;
        
        //similar to level order
        queue<pair<TreeNode *, unsigned long long int>> q;
        int maxwidth =0;
        q.push(make_pair(root, 0));
        
        while(!q.empty()){
            
            
            unsigned long long int left_index = q.front().second, right_index = 0;
            unsigned long long int sz = q.size();
            
            
            for(unsigned long long int i=0; i<sz; i++){
                
                pair<TreeNode *, unsigned long long int> p = q.front();
                q.pop();
                TreeNode *temp = p.first;
                right_index = p.second;
                
                if(temp->left)
                    q.push(make_pair(temp->left, 2*right_index + 1));
                if(temp->right)
                    q.push(make_pair(temp->right, 2*right_index + 2));
                
            }
            
            maxwidth = max(maxwidth, int(right_index - left_index + 1));
        }
        
        return maxwidth;
    }
};