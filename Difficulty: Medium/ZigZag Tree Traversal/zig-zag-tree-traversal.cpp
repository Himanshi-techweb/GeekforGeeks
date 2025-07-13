/*Structure of the node of the binary tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    // Function to store the zig zag order traversal of tree in a list.
    vector<int> zigZagTraversal(Node* root) {
        // Code here
        bool ltor=true;
        vector<int> ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
          int size=q.size();
          vector<int> store;
          for(int i=0;i<size;i++){
              auto front=q.front();q.pop();
              store.push_back(front->data);
              if(front->left)q.push(front->left);
              if(front->right)q.push(front->right);
          }
          if(!ltor)reverse(store.begin(),store.end());
          ans.insert(ans.end(),store.begin(),store.end());
          ltor=!ltor;
        }
        return ans;
    }
};