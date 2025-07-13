/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
    
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int solve(Node* root){
       if(root==NULL)return 0;
       if(root->left==NULL && root->right==NULL){
            int x=root->data;
            root->data=0;
            return x;
        }
        int lsum=solve(root->left);
        int rsum=solve(root->right);
        int actual=root->data;
        root->data=lsum+rsum;
        return root->data+actual; 
    }
    void toSumTree(Node *root) {
        // Your code here
        solve(root);
    }
};