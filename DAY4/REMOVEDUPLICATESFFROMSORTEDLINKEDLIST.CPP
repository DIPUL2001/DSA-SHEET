 ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr){
            return head;
        }
       ListNode* curr=head;
      
        while(curr!=nullptr){
            if(curr->next!=nullptr && (curr->val==curr->next->val)){
                ListNode* next_next=curr->next->next;
                ListNode* nodetodelete=curr->next;
                delete(nodetodelete);
                 curr->next=next_next;
            }  
            else{
                curr=curr->next;
                    
            }
        }
        return head;
    }