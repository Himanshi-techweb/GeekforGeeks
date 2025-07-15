// User function Template for C++

/* Node of the binary search tree
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void in(Node* root,Node* &prev){
        if(root==NULL)return;
        in(root->left,prev);
        if(prev)prev->right=root;
        root->left=NULL;
        prev=root;
        in(root->right,prev);
    }
    Node *flattenBST(Node *root) {
        // code here
        Node* prev=NULL;
        Node* x=new Node(-1);
        prev=x;
        in(root,prev);
        return x->right;
    }
};