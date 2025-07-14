/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
  public:
    Node* solve(Node* root,int n1,int n2){
        if(root==NULL || root->data==n1 || root->data==n2)return root;
        auto left=solve(root->left,n1,n2);
        auto right=solve(root->right,n1,n2);
        if(!left)return right;
        if(!right)return left;
        return root;
    }
    // Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root, int n1, int n2) {
        // Your code here
        return solve(root,n1,n2);
    }
};