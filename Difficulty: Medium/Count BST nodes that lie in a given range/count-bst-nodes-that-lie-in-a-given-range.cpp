/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    int cnt=0;
    void solve(Node* root,int l,int h){
      if(root==NULL)return; 
      solve(root->left,l,h);
      if(root->data>=l && root->data<=h)cnt++;
      solve(root->right,l,h);
    }
    int getCount(Node *root, int l, int h) {
        // your code here
        solve(root,l,h);
        return cnt;
    }
};