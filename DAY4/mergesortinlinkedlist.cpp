 ListNode* solve(ListNode* list1, ListNode* list2){
        if(list1->next == nullptr)
   {
    list1->next = list2;
       return list1;
   }
   ListNode* curr1 = list1;
   ListNode* next1 = curr1->next;
   ListNode* curr2 = list2;
   ListNode* next2 = curr2->next;
   while(next1 != nullptr && curr2 != nullptr)
   {
    if( (curr2->val >= curr1->val) && (curr2->val <= next1->val) )
       {
           // add node in between first list
           curr1->next = curr2;
           next2 = curr2->next;
           curr2->next = next1;
           // update pointers
           curr1 = curr2;
           curr2 = next2;
       }
       else
       {
           curr1 = next1;
           next1 = next1->next;
           if(next1 == nullptr)
           {
               curr1->next = curr2;
               return list1;
           }
       }
   }
   return list1;
    }
    
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
         if(list1==nullptr)
       return list2;   
    if(list2==nullptr)
        return list1; 
    if(list1->val<=list2->val){
        return solve(list1,list2);
    }
    else{
        return solve(list2,list1);
    }
    }