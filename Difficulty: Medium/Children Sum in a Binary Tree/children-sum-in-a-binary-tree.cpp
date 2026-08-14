/* Structure of a Tree Node
class Node {
public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    pair<int,bool> solve(Node* root){
        if(root==NULL)return {0,true};
        if(root->left==NULL && root->right==NULL)return {root->data,true};
        pair<int,bool> l=solve(root->left);
        pair<int,bool> r=solve(root->right);
        bool ans=((l.first+r.first)==root->data)&&l.second&&r.second;
        return {root->data,ans};
        
        
    }
    bool isSumProperty(Node *root) {
        // code here
        auto ans=solve(root);
        return ans.second;
        
    }
};