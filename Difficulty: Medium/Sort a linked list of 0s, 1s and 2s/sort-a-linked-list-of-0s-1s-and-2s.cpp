/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        Node dummyzero(0),dummyone(0),dummytwo(0);
        Node* zero=&dummyzero;
        
        Node* one=&dummyone;
        
        Node* two=&dummytwo;
        Node* curr=head;
        //Zero
        while(curr ){
           if(curr->data==0 ){
               zero->next=curr;
               
               zero=zero->next;
               
               
           }
           else if(curr->data==1 ){
               one->next=curr;
               one=one->next;
               
               
           }
           else {
               two->next=curr;
               two=two->next;
               
           }
           curr=curr->next;
           
        }
        zero->next=(dummyone.next!=NULL)?dummyone.next:dummytwo.next;
        one->next=dummytwo.next;
        two->next=NULL;
        return dummyzero.next;
        
        
    }
};