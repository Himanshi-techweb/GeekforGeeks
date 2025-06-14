/* BST Node
class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    Node* succ=NULL;Node* pre=NULL;
    void check(Node *root,int x){
        if(root==NULL)return;
        if(root->data>x){
            succ=root;
            check(root->left,x);
        }
        if(root->data<=x){
          check(root->right,x);  
        }
    }
    void check2(Node *root,int x){
        if(root==NULL)return;
        if(root->data>=x){
            check2(root->left,x);
        }
        if(root->data<x){
          pre=root;  
          check2(root->right,x);  
        }
    }
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        if(root==NULL)return {pre,succ};
        check(root,key);
        check2(root,key);
        return {pre,succ};
        
    }
};