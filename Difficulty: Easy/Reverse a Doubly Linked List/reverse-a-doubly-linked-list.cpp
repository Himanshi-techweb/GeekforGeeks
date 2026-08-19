/* Structure of Doubly Linked List Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        Node* prev=NULL;
        Node* curr=head;
        while(curr){
           prev=curr->prev;
           curr->prev=curr->next;
           curr->next=prev;
           
           curr= curr->prev;
        }
        return prev->prev;
    }
};