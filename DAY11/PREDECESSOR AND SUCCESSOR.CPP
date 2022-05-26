void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
// Your code goes here
    if(!root)
    return;
    if(root->key==key){
        Node *tmp;
        if(root->left){
            tmp=root->left;
            while(tmp->right)
            tmp=tmp->right;
            pre=tmp;
        }
        if(root->right){
            tmp=root->right;
            while(tmp->left)
            tmp=tmp->left;
            suc=tmp;
        }
        return;
    }
    if(key<root->key){
        suc=root;
        findPreSuc(root->left,pre,suc,key);
        return;
    }
    pre=root;
    findPreSuc(root->right,pre,suc,key);
    return;
}