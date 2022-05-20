 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(0);
        ListNode* head=dummy;
        int carry=0;
        while(l1!=nullptr || l2!=nullptr || carry>0){
        int val1=0;
        if(l1!=nullptr){
            val1=l1->val;
        }
        int val2=0;
        if(l2!=nullptr){
            val2=l2->val;
        }
        int sum=val1+val2+carry;
        int rem=sum%10;
        int quo=sum/10;
        carry=quo;
        ListNode* temp=new ListNode(rem);
        head->next=temp;
        head=head->next;
        if(l1!=NULL){
            l1=l1->next;
        }
        if(l2!=NULL){
            l2=l2->next;
        }
    }
     return dummy->next;   
    }