/* The Node structure is
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void inorder(Node* root,vector<int>&in){
        if(root==NULL)return;
        inorder(root->left,in);
        in.push_back(root->data);
        inorder(root->right,in);
    }
    void build(int &i,Node* root,vector<int>&in){
        if(i>=in.size() || root==NULL)return;
        build(i,root->left,in);
        root->data=in[i++];
        build(i,root->right,in);
    }
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    Node *binaryTreeToBST(Node *root) {
        // Your code goes here
        vector<int> in;
        inorder(root,in);
        sort(in.begin(),in.end());
        int i=0;
        build(i,root,in);
        return root;
    }
};