/* Structure of a Binary Tree Node
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
    int ans=-1;
    void solve(Node* root,int &k){
        if(k<0 || root==NULL)return;
        solve(root->right,k);
        k--;
        if(k==0){
            ans=root->data;
            return;
        }
        solve(root->left,k);
    }
    int kthLargest(Node *root, int k) {
        // code here
        int x=k;
        solve(root,k);
        return ans;
    }
};