/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution {
  public:
    bool check(Node* root){
        if(root==NULL || (root->left==NULL && root->right==NULL))return true;
        
    int left = 0;
    if (root->left) {
        // If child is a leaf, just take its value
        if (!root->left->left && !root->left->right)
            left = root->left->data;
        else
            left = 2 * root->left->data;  // sum of subtree rooted at left
    }

    int right = 0;
    if (root->right) {
        if (!root->right->left && !root->right->right)
            right = root->right->data;
        else
            right = 2 * root->right->data;  // sum of subtree rooted at right
    }
        bool condition=(root->data==left+right);
        return condition&&check(root->left) && check(root->right);
    }
    bool isSumTree(Node* root) {
        // Your code here
        return check(root);
    }
};