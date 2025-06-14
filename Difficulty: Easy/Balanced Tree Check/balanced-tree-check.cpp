/* A binary tree node structure

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
    int height(Node* root){
      if(root==NULL)return 0;
      int lh=height(root->left);
      int rh=height(root->right);
      return 1+max(lh,rh);
    }
    bool isBalanced(Node* root) {
        // Code here
        if(root==NULL)return true;
        int left=height(root->left);
        int right=height(root->right);
        bool cond=(abs(left-right)<=1);
        return cond&&isBalanced(root->left)&&isBalanced(root->right);
    }
};