/* Structure of binary tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    Node* solve(int n1,int n2,Node* root){
        if(root==NULL || root->data==n1 || root->data==n2)return root;
        Node* l=solve(n1,n2,root->left);
        Node* r=solve(n1,n2,root->right);
        if(l!=NULL && r!=NULL)return root;
        if(l==NULL)return r;
        return l;
    }
    Node* lca(Node* root, int n1, int n2) {
        //  code here
        return solve(n1,n2,root);
        
    }
};