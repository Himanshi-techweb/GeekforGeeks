/* Structure of Linked List Node
class Node {
  public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/

class Solution {
  public:
    Node* insertPos(Node* head, int pos, int val) {
        // code here
        int cnt=1;
        
        if(pos==1){
            Node* curr=new Node(val);
            curr->next=head;
            return curr;
            
        }
        Node* curr=head;
        while(cnt<pos-1){
           curr=curr->next;
           cnt++;
        }
        Node* st=curr->next;
        Node* t=new Node(val);
        curr->next=t;
        t->next=st;
        return head;
        
        
    }
};