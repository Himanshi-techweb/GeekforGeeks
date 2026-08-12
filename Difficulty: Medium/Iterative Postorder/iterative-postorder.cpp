/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/
class Solution {
  public:
    vector<int> postOrder(Node* node) {
        // code here
        if(node==NULL)return {};
        stack<Node*> st;
        vector<int>ans;
        Node* curr=node;
        Node* endvisit=NULL;
        while(curr || !st.empty()){
            if(curr){
                st.push(curr);
                curr=curr->left;
            }
            else{
                Node* peaknode=st.top();
                if(peaknode->right && endvisit!=peaknode->right){
                    curr=peaknode->right;
                }
                else{
                    ans.push_back(peaknode->data);
                    endvisit=peaknode;
                    st.pop();
                }
            }
        }
        return ans;
    }
};