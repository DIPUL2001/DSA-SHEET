struct node{
   node *next[26]={NULL};
   bool isLeaf=false;
};
class trie{
 node *root;
 public:
 trie(){
     root= new node;
 }
 void insert(string &s){
     node *head=root;
     for(int i=0;i<s.size();i++){
         if(!head->next[s[i]-'a']) head->next[s[i]-'a']=new node;
         head=head->next[s[i]-'a'];
     }
     head->isLeaf=true;
 }
 
 void func(node *head,string &t,vector<string> &ans){
     if(head->isLeaf) ans.push_back(t);
     for(int i=0;i<26;i++){
         if(head->next[i]){
             t.push_back('a'+i);
             func(head->next[i],t,ans);
             t.pop_back(); // backtracking
         }
     }
 }
 
 vector<string> pre(string &p){
     node *head=root;
     for(int i=0;i<p.size();i++){
         if(!head->next[p[i]-'a']) head->next[p[i]-'a']=new node;
         head=head->next[p[i]-'a'];
     }
     vector<string> ans;
     func(head,p,ans);
     if(ans.empty()) ans.push_back("0");
     return ans;
 }
};
class Solution{
public:
   vector<vector<string>> displayContacts(int n, string contact[], string s)
   {
       trie *t=new trie();
       for(int i=0;i<n;i++) t->insert(contact[i]);
       string p;
       vector<vector<string>> ans;
       for(auto i:s){
           p.push_back(i);
           ans.push_back(t->pre(p));
       }
       return ans;
   }
};
