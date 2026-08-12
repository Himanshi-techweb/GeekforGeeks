/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    vector<int> preOrder(Node* root) {
        // code here
        stack<Node*> q;
        if(root==NULL)return {};
        vector<int> ans;
        q.push(root);
        while(!q.empty()){
            auto front=q.top();
            ans.push_back(front->data);
            q.pop();
            if(front->right)q.push(front->right);
            if(front->left)q.push(front->left);
            
        }
        return ans;
    }
};