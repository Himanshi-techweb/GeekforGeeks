/* The structure of the binary tree is as follows
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
  public:
    /*You are required to complete this method*/
    int height(Node * root){
        if(root==NULL)return 0;
        int lh=height(root->left);
        int rh=height(root->right);
        return 1+max(lh,rh);
    }
    bool solve(int h,Node* root,int lvl){
        if(root==NULL)return true;
        bool condition=true;
        if(root->left==NULL && root->right==NULL){
            condition= (lvl+1==h);
        }
        return condition&&solve(h,root->left,lvl+1) &&solve(h,root->right,lvl+1);
        
    }
    bool check(Node *root) {
        // Your code here
        int h=height(root);
        return solve(h,root,0);
    }
};