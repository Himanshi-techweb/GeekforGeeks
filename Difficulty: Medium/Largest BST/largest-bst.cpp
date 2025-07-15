/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    int ans=0;
    pair<int,pair<int,int>> solve(Node* root){//sizez,maxi,mini
        if(root==NULL)return {0,{INT_MIN,INT_MAX}};
        if(!root->left && !root->right)return {1,{root->data,root->data}};
        auto l=solve(root->left);
        auto r=solve(root->right);
        if(l.second.first<root->data && r.second.second>root->data){
            return {l.first+r.first+1,{max(root->data,r.second.first),min(root->data,l.second.second)}};
        }
        else{
            return {max(l.first,r.first),{INT_MAX,INT_MIN}};
        }
    }
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root) {
        // Your code here
        auto ans=solve(root);
        return ans.first;
    }
};