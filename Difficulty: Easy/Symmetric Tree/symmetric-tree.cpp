/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool solve(Node* x,Node* y){
        if(x==NULL && y==NULL)return true;
        if(x==NULL || y==NULL || x->data!=y->data)return false;
        return (solve(x->left,y->right)&&solve(x->right,y->left)&& (x->data==y->data));
    }
    bool isSymmetric(Node* root) {
        // code here
        if(root==NULL)return true;
        if(root->left==NULL && root->right==NULL)return true;
        return solve(root->left,root->right);
        
    }
};