/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  public:
    vector<int> inOrder(Node* root) {
        // code here
        if(root==NULL)return {};
        stack<Node*> st;
        Node* curr=root;
        vector<int> ans;
        
        while(curr || !st.empty()){
            while(curr){
                st.push(curr);
                curr=curr->left;
            }
            curr=st.top();st.pop();
            ans.push_back(curr->data);
            curr=curr->right;
            
            
        }
        return ans;
    }
};