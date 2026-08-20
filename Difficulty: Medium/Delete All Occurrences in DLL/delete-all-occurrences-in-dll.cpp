/* a Node of the doubly linked list
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};*/

class Solution {
  public:
    Node* deleteAllOccurOfX(Node* head, int x) {
        // code here
        Node* dummy=new Node(-1);
        dummy->next=head;
        
        head->prev=dummy;
        Node* curr=head;
        while(curr ){
            Node* prev=curr->prev;
            Node* next=curr->next;
            if(curr->data==x){
                Node* todelete=curr;
                
                prev->next=next;
                if(next)next->prev=prev;
                delete todelete;
            }
            curr=next;
            
        }
        Node* newnode=dummy->next;
        if(newnode==NULL)return NULL;
        return newnode;
        
    }
};