// User Fuction template for C++
/*
// Tree Node
class Node {
public:
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
    int sum=INT_MIN;
    // Function to return maximum path sum from any node in a tree.
    int findMaxSum1(Node *root) {
        // code here
        if(root==NULL)return 0;
        int l=findMaxSum1(root->left);
        if(l<0)l=0;
        int r=findMaxSum1(root->right);
        if(r<0)r=0;
        sum=max(sum,root->data+l+r);
        return root->data+max(l,r);
    }
    int findMaxSum(Node* root){
        findMaxSum1(root);
        return sum;
    }
};