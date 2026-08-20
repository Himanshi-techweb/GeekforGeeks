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
}; */

class Solution {
  public:
    vector<vector<int>> givenSumPairs(Node* head, int target) {
        // code here
        vector<vector<int>> ans;
        Node* tail=head;
        Node* curr=head;
        while(tail->next!=NULL){
            tail=tail->next;
        }
        
        while(curr!=tail){
            int sum=curr->data+tail->data;
            if(curr->next==tail && sum==target){
                ans.push_back({curr->data,tail->data});
                break;
            }
            // cout<<sum<<endl;
            if(sum==target){
                ans.push_back({curr->data,tail->data});
                curr=curr->next;
                tail=tail->prev;
            }
            else if(sum<target)curr=curr->next;
            else tail=tail->prev;
        }
        return ans;
        
    }
};