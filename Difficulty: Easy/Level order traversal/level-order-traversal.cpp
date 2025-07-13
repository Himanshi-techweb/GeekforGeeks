/* A binary tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        // Your code here
        queue<Node*>q;
        q.push(root);
        vector<vector<int>> ans;
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
           ans.push_back(check);
        }
        return ans;
    }
};