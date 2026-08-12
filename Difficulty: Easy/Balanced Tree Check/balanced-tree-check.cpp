/* Structure of binary tree node
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
    int solve1(Node* root){
        if(root==NULL)return 0;
        int left=solve1(root->left);
        int right=solve1(root->right);
        return 1+max(left,right);
    }
    bool solve2(Node* root){
        if(root==NULL)return true;
        int left=solve1(root->left);
        int right=solve1(root->right);
        if(abs(right-left)>1)return false;
        return (solve2(root->left)&& solve2(root->right));
    }
    // int solve(Node* root){
    //     if(root==NULL)return 0;
    //     int left=solve(root->left);
    //     int right=solve(root->right);
    //     if(abs(right-left)>1)return -1;
    //     if(left==-1 || right==-1)return 0;
    //     return 1+max(left,right);
    // }
    bool isBalanced(Node* root) {
        // code here
        return solve2(root);
        
        
    }
};