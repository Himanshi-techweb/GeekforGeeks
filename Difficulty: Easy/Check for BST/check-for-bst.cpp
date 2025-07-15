class Solution {
  public:
    // Function to check whether a Binary Tree is BST or not.
    bool check(Node* root,int mini,int maxi){
        if(root==NULL)return true;
        if(!check(root->left,mini,root->data)|| !check(root->right,root->data,maxi)) return false;
        if((root->data>maxi) || (root->data<mini))return false;
        return true;
    }
    bool isBST(Node* root) {
       return check(root,INT_MIN,INT_MAX);
    }
};