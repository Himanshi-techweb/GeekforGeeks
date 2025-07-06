/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/
class compare{
  public:
  bool operator()(Node* a,Node* b){
      return a->data>b->data;
  }  
};
class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        int n=arr.size();
        priority_queue<Node*,vector<Node*> ,compare>q;
        for(int i=0;i<n;i++){
          q.push(arr[i]);  
        }
        Node* head=NULL;Node* tail=NULL;
        while(q.size()>0){
            Node* top=q.top();q.pop();
            if(top->next)q.push(top->next);
            if(head==NULL){
                head=top;tail=top;
            }
            else{
                tail->next=top;
                tail=top;
            }
        }
        return head;
    }
};