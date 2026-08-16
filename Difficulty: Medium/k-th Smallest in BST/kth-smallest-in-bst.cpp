/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int ans=-1;
    void solve(Node* root,int &k){
        if(root==NULL || k<0)return ;
        
        
        solve(root->left,k);
        k--;
        if(k==0){
            ans=root->data;
            return;
        }
        
        
        solve(root->right,k);
        
    }
    int kthSmallest(Node *root, int k) {
        // code here
        int x=k;
        solve(root,x);
        return ans;
    }
};