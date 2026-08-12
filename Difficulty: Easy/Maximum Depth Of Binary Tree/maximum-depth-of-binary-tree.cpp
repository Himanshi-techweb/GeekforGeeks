/* The Node structure is
class Node {
public:
    int data;
    Node* left;
    Node* right;

};
}; */

class Solution {
  public:
    int solve(Node* root){
        if(root==NULL)return 0;
        int left=solve(root->left);
        int right=solve(root->right);
        return 1+max(left,right);
    }
    int maxDepth(Node *root) {
        // code here
        return solve(root);
        
    }
};
