/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};
*/
class Solution {
  public:
    void check(int k,Node* mainnode,Node* &next1){
        if(mainnode==NULL)return;
        if(mainnode->data>k){
            next1=mainnode;
            check(k,mainnode->left,next1);
        }
        else{
            check(k,mainnode->right,next1);
        }
    }
    void solve(Node* root,Node* mainnode){
        if(root==NULL)return;
        check(root->data,mainnode,root->next);
        if(root->left)solve(root->left,mainnode);
        if(root->right)solve(root->right,mainnode); 
    }
    void populateNext(Node *root) {
        // code here
        Node* temp=root;
        solve(root,root);
    }
};