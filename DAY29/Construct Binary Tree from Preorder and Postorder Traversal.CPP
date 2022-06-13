class Solution {
public:
   TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
     
        //map all the elements of postorder with their index
        
        unordered_map<int,int> mp;
        for(int i=0;i<post.size();i++)
            mp[post[i]]=i;
        
        int preorderIndex=0;
        return buildTree(pre,mp,preorderIndex);
        
    }
    TreeNode* buildTree(vector<int>& pre,unordered_map<int,int>& mp,int& preorderIndex)
    {
        int curr=pre[preorderIndex];
        TreeNode* n=new TreeNode(curr);
        preorderIndex++;
        if(preorderIndex<pre.size()  && mp[pre[preorderIndex]] < mp[curr])
        {
            //the next elemenet is present to the left of tree
            n->left=buildTree(pre,mp,preorderIndex);
        }
        else 
            return n;
        if(preorderIndex < pre.size() && mp[pre[preorderIndex]] < mp[curr])
        {
            n->right=buildTree(pre,mp,preorderIndex);
        }
        return n;
        
    }
};