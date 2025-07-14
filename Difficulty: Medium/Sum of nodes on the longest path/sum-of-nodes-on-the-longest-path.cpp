/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    int ans=0;
    int height(Node* root){
        if(root==NULL)return 0;
        return 1+max(height(root->left),height(root->right));
    }
    void sumcheck(Node* root,int lvl,int h,int sum){
        if(root==NULL)return;
        sum=sum+root->data;
        if(lvl+1==h && root->left==NULL && root->right==NULL){
            ans=max(sum,ans);
        }
        sumcheck(root->left,lvl+1,h,sum);
        sumcheck(root->right,lvl+1,h,sum);
    }
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        int h=height(root);
        int sum=0;
        sumcheck(root,0,h,sum);
        return ans;
    }
};