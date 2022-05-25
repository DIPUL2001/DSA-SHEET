 pair<bool,int> isBalancedFast(TreeNode* root){
        //basecase
        if(root==NULL){
            pair<bool,int> p=make_pair(true,0);
            return p;
        }
          pair<bool,int>  isleft=isBalancedFast(root->left);
          pair<bool,int>  isright=isBalancedFast(root->right);
        
          bool leftans=isleft.first;
          bool rightans=isright.first;
           
          bool diff=abs(isleft.second-isright.second)<=1;
           
           pair<bool,int> ans;
           ans.second=max(isleft.second,isright.second)+1;
           
          if(leftans && rightans && diff){
              ans.first=true;
          }
        else{
            ans.first=false;
        }
           return ans;
    }
    bool isBalanced(TreeNode* root) {
        return isBalancedFast(root).first;
    }