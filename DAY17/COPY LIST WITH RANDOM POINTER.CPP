/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
 private:
   void insertAtTail(Node* &head,Node* &tail,int val)
   {
      Node* newnode=new Node(val);
      if(head==NULL){
          head=newnode;
          tail=newnode;    //clone is created
       }                        
      else{
           tail->next=newnode;
           tail=newnode;
      }
   }
public:
    Node* copyRandomList(Node* head) {
         //step1 : create a clone 
        Node* cloneh=NULL;
        Node* clonet=NULL;
        Node* temp=head;
        while(temp!=NULL){
            insertAtTail(cloneh,clonet,temp->val);
            temp=temp->next;
        }
        
        //step2 :clone node add b/w original node;
        Node* cn=cloneh;
        Node* on=head;
        while(on!=NULL && cn!=NULL){
            Node* next=on->next;
            on->next=cn;  //original node
            on=next;
             
            next=cn->next;
            cn->next=on;   //clone node
            cn=next;
        }
        //step 3: random ptr
         temp=head;
         while(temp!=NULL){
            if(temp->next!=NULL){
                temp->next->random=temp->random?temp->random->next:temp->random;
        }
        temp=temp->next->next;
    }
    // step 4:revert step 2
    on=head;
    cn=cloneh;
     while(on!=NULL && cn!=NULL){
         on->next=cn->next;
         on=on->next;
         if(on!=NULL){
             cn->next=on->next;
         }
         cn=cn->next;
     }
     return cloneh;
    }
};