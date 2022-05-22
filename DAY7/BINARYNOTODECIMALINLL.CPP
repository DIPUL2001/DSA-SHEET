  int getDecimalValue(ListNode* head) {
       int ans=0;
       ListNode* temp=head;
       while(temp!=NULL){
           ans*=2;
           ans+=(temp->val);
           temp=temp->next;
       }
        return ans;
    }