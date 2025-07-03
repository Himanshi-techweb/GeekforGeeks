/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    Node* check(Node* root,Node* p ,Node* q){
        if(root==NULL || root==p || root==q)return root;
        Node* left=NULL;Node* right=NULL;
        if(p->data<root->data && q->data<root->data)left=check(root->left,p,q);
        else if(p->data>root->data && q->data>root->data)right=check(root->right,p,q);
        else if((p->data<root->data && q->data>root->data) ||
        (p->data>root->data && q->data<root->data))return root;
        if(left)return left;
        else if(right)return right;
    }
    Node* LCA(Node* root, Node* p, Node* q) {
        // code here
        return check(root,p,q);
    }
};



















