/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* newNode(int val) {
    return new Node(val);
}
*/

class Solution {
  public:
    int diam=0;
    int height(Node* root){
        if(root==NULL)return 0;
        int lh=height(root->left);
        int rh=height(root->right);
        diam=max(diam,lh+rh);
        return 1+max(lh,rh);
    }
    int diameter(Node* root) {
        // Your code here
        height(root);
        return diam;
    }
};