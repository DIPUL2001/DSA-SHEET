Node* flatten(Node* head) {
        if(!head) return head;
        Node *temp = head;
        stack<Node*> st;
        while(temp){
            if(temp->child!=NULL){
                if(temp->next!=NULL) st.push(temp->next);
                temp->child->prev = temp;
                temp->next = temp->child;
                temp->child = NULL;
            }
            if(!temp->next && !st.empty()){
                Node* top = st.top();
                st.pop();
                temp->next = top;
                top->prev = temp;
            }
            temp = temp->next;
        }
        return head;   
    }