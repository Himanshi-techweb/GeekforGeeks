/*
Structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left, *right;
};
*/
// your task is to complete this function
class Solution {
  public:
    bool solve(Node* root,int node,vector<int> & arr){
        if(root==NULL)return false;
        arr.push_back(root->data);
        if(root->data==node)return true;
        if(solve(root->left,node,arr) || solve(root->right,node,arr))return true;
        arr.pop_back();
        return false;
    }
    int kthAncestor(Node *root, int k, int node) {
        // Code here
        vector<int> arr;
        solve(root,node,arr);
        reverse(arr.begin(),arr.end());
        int ans=-1;
        if(k<arr.size())ans=arr[k];
        return ans;
        
        
    }
};
