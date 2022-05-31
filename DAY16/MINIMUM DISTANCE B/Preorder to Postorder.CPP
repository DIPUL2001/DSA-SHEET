Node* create(int pre[],int &i,int upperBound,int size)
{
   if(i>=size || pre[i]>upperBound) return NULL;
   Node* root=newNode(pre[i++]);
   root->left=create(pre,i,root->data,size);
   root->right=create(pre,i,upperBound,size);
   
   return root;
}
Node* post_order(int pre[], int size)
{
   if(!size) return NULL;
   int i=0;
   Node* root=create(pre,i,INT_MAX,size);
   
   return root;
}