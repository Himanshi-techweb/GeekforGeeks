/*
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
class Solution {
  public:
    vector<int> reverseLevelOrder(Node *root) {
        // code here
        queue<Node*>q;
        q.push(root);
        vector<int> ans;
        stack<vector<int>> store;
        while(!q.empty()){
           int size=q.size();
           vector<int> check;
           for(int i=0;i<size;i++){
            auto front=q.front();
            q.pop();
            check.push_back(front->data);
            if(front->left)q.push(front->left);
            if(front->right)q.push(front->right);
           }
           store.push(check);        
        }
        while(!store.empty()){
            ans.insert(ans.end(),store.top().begin(),store.top().end());
            store.pop();
        }
        return ans;
    }
};