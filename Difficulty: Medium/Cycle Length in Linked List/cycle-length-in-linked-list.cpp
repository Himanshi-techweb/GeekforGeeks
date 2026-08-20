/* Structure of Linked List Node
class Node {
 public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        Node* fast=head;
        Node* slow=head;
        int cnt=0;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                cnt++;
                slow=slow->next;
                while(slow!=fast){
                    slow=slow->next;
                    cnt++;
                }
                break;
            }
        }
        //now traverse fast again
        
        return cnt;
        
    }
};