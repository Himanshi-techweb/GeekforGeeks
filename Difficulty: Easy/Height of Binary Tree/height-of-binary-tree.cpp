/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int solve(Node* node){
        if(node==NULL || (node->left==NULL && node->right==NULL))return 0; 
        int lh=solve(node->left);
        int rh=solve(node->right);
        return 1+max(lh,rh);
    }
    int height(Node* node) {
        // code here
        return solve(node);
    }
};