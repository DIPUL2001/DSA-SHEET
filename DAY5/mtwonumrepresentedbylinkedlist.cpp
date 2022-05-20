//This solution is taken by geeks for geeks platform

// C++ program to Multiply two numbers
// represented as linked lists
#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
   
// Linked list node
struct Node
{
    int data;
    struct Node* next;
};
   
// Function to create a new node
// with given data
struct Node *newNode(int data)
{
    struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
   
// Function to insert a node at the
// beginning of the Linked List
void push(struct Node** head_ref, int new_data)
{
    // allocate node
    struct Node* new_node = newNode(new_data);
   
    // link the old list off the new node
    new_node->next = (*head_ref);
   
    // move the head to point to the new node
    (*head_ref) = new_node;
}
   
// Multiply contents of two linked lists
long long multiplyTwoLists (Node* first, Node* second)
{
    long long N= 1000000007;
    long long num1 = 0, num2 = 0;
    while (first || second){
         
        if(first){
            num1 = ((num1)*10)%N + first->data;
            first = first->next;
        }
         
        if(second)
        {
            num2 = ((num2)*10)%N + second->data;
            second = second->next;
        }
         
    }
    return ((num1%N)*(num2%N))%N;
}
   
// A utility function to print a linked list
void printList(struct Node *node)
{
    while(node != NULL)
    {
        cout<<node->data;
        if(node->next)
            cout<<"->";
        node = node->next;
    }
    cout<<"\n";
}
   
// Driver program to test above function
int main()
{
    struct Node* first = NULL;
    struct Node* second = NULL;
   
    // create first list 9->4->6
    push(&first, 6);
    push(&first, 4);
    push(&first, 9);
    printf("First List is: ");
    printList(first);
   
    // create second list 8->4
    push(&second, 4);
    push(&second, 8);
    printf("Second List is: ");
    printList(second);
   
    // Multiply the two lists and see result
    cout<<"Result is: ";
    cout<<multiplyTwoLists(first, second);
   
    return 0;
}