/*The structure of Node

struct Node {
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
    int succ=-1;
    void check(Node *root,Node *x){
        if(root==NULL)return;
        if(root->data>x->data){
            succ=root->data;
            check(root->left,x);
        }
        if(root->data<=x->data){
          check(root->right,x);  
        }
    }
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    int inOrderSuccessor(Node *root, Node *x) {
        // Your code here
        if(root==NULL)return -1;
        check(root,x);
        return succ;
    }
};