/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> ans;
    void solve(Node* root,vector<int> &curr){
        if(root==NULL)return;
        curr.push_back(root->data);
        if(root->left==NULL && root->right==NULL){
            // curr.push_back(root->data);
            ans.push_back(curr);
            // return;
        }
        solve(root->left,curr);
        solve(root->right,curr);
        curr.pop_back();
        
    } 
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<int> curr;
        solve(root,curr);
        return ans;
    }
};