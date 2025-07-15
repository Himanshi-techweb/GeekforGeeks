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
        if(root==NULL || root->data==p->data || root->data==q->data)return root;
        if(p->data<root->data && q->data<root->data)return check(root->left,p,q);
        else if(p->data>root->data && q->data>root->data)return check(root->right,p,q);
        return root;
    }
    Node* LCA(Node* root, Node* p, Node* q) {
        // code here
        return check(root,p,q);
    }
};



















