/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
    Node* mergeLL(Node* a, Node* b){
        Node* temp = new Node(-1);
        Node* res = temp;
        
        while(a && b){
            if(a->data < b->data){
                temp->bottom = a;
                temp = temp->bottom;
                a = a->bottom;
            } else{
                temp->bottom = b;
                temp = temp->bottom;
                b = b->bottom;
            }
        }
        
        if(a)   temp->bottom = a;
        else    temp->bottom = b;
        
        return res->bottom;
    }
    
  public:
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        // Your code here
        if(!root || !root->next)    return root;
        root->next = flatten(root->next);
        return mergeLL(root, root->next);
    }
};