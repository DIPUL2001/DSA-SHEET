class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        Node* newHead = new Node();
        Node* temp = newHead;
        
        // your code here
        Node* curr = root;
        stack<Node*> st;
        while(curr != NULL || st.empty() == false) {
            while(curr != NULL) {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            temp->right = curr;
            curr->left = temp;
            temp = temp->right;
            st.pop();
            curr = curr->right;
        }
        
        temp->right = NULL;
        newHead = newHead->right;
        newHead->left = NULL;
        
        return newHead;
    }
};