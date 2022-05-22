/*IT IS DONE WITH THE HELP OF STACK ;
*/
 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         stack<int>s1;
        stack<int>s2;
        stack<int>s;
        
        while(l1){
            s1.push(l1->val);
            l1=l1->next;
        }
        while(l2){
            s2.push(l2->val);
            l2=l2->next;
        }
        int carry=0;
        while( !s1.empty() || !s2.empty() || carry!=0){
            int s1val=!s1.empty() ?s1.top(): 0;
            int s2val=!s2.empty() ?s2.top(): 0;
            
            int current_sum=s1val+s2val+ carry;
            
            int finaldigit=current_sum%10;
            carry= current_sum/10;
            
            s.push(finaldigit);
            if(!s1.empty()){
                s1.pop();
            }
            if(!s2.empty()){
                s2.pop();
            }
        }
        
        ListNode* dummy=new ListNode(-1);
        ListNode* l3=dummy;
        while(!s.empty()){
            ListNode* new_node=new ListNode(s.top());
            l3->next=new_node;
            l3=l3->next;
            
            s.pop();
        }
        return dummy->next;
        
        
    }