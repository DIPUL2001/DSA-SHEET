bool solve(Node* root, int mn, int mx){
   
   if(root == NULL) return 0;
   if(root->data == mn and root->data == mx) return 1;
   
   return solve(root->left, mn, root->data - 1) or solve(root->right, root->data+1, mx);
   
}
bool isDeadEnd(Node *root)
{
   int mn = 1, mx = INT_MAX;
   return solve(root, mn, mx);
}