Node *merge(Node *a,Node *b){
    Node *c=new Node(0);
    Node *dummy=c;
    while(a && b){
        if(a->data<=b->data){
            c->bottom=a;
            c=c->bottom;
            a=a->bottom;
        }else{
            c->bottom=b;
            c=c->bottom;
            b=b->bottom;
        }
    }
    
    if(a){
        c->bottom=a;
    }else{
        c->bottom=b;
    }
    return dummy->bottom;
}
    
Node *flatten(Node *root){
    if(root==NULL) return NULL;
   return merge(root,flatten(root->next));
}
