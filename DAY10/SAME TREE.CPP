 bool isSameTree(TreeNode* p, TreeNode* q) {
        //3 base case;
        if(p==NULL && q==NULL){
            return true;
        }
        if(p!=NULL && q==NULL){
            return false;
        }
        if(p==NULL && q!=NULL){
            return false;
        }
        bool isleft=isSameTree(p->left,q->left);
        bool isright=isSameTree(p->right,q->right);
        
        bool value=q->val==p->val;
        if(isleft && isright && value){
            return true;
        }
        else{
            return false;
        }
    }