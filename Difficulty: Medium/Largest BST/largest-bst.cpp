/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    int ans=0;
    pair<int,pair<int,int>> solve(Node* root){
        //return three thing how many nodes count and minimum and maximum
        if(root==NULL)return {0,{INT_MAX,INT_MIN}};
        auto l=solve(root->left);
        auto r=solve(root->right);
        
        //
        if(l.second.second<root->data && r.second.first>root->data){
           int x=l.first+r.first+1;
           ans=max(ans,x);
           int mn=min(l.second.first,root->data);
           int mx=max(r.second.second,root->data);
           return {x,{mn,mx}};
        }
        else return {1,{INT_MIN,INT_MAX}};
    }
    int largestBst(Node *root) {
        // code here
        solve(root);
        return ans;
    }
};