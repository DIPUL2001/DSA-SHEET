class Solution
{
    public:
    Node *zigZag(Node* head)
    {
      bool flag = 1;
       Node* curr = head;
       while(curr->next)
       {
           if(flag)
           {
               if(curr->data > curr->next->data)
               {
                   swap(curr->data,curr->next->data);
               }
           }
           else
           {
               if(curr->data < curr->next->data)
               {
                   swap(curr->data,curr->next->data);
               }
           }
           
           flag = !flag;
           curr = curr->next;
       }
       
       return head;
    }