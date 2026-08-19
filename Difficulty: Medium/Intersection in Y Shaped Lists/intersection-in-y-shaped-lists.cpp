/* Structure of Linked List Node
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};*/

class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        //  code here
        unordered_map<Node*,bool> st;
        Node* curr=head1;
        while(curr){
            st[curr]=true;
            curr=curr->next;
        }
        curr=head2;
        while(curr){
            if(st.find(curr)!=st.end()){
                return curr;
            }
            curr=curr->next;
        }
        return NULL;
    }
};