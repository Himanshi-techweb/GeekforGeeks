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
class NodeValue{
    public:
    int size;int mini;int maxi;
    NodeValue(int mini,int maxi,int size){
        this->mini=mini;this->maxi=maxi;this->size=size;
    }
};
class Solution {
    
  public:
    NodeValue solve(Node* root){
        if(root==NULL)return NodeValue(INT_MAX,INT_MIN,0);
        auto left=solve(root->left);
        auto right=solve(root->right);
        if(left.maxi<root->data && right.mini>root->data){
            return NodeValue(min(root->data,left.mini),max(root->data,right.maxi),left.size+right.size+1);
        }
        return NodeValue(INT_MIN,INT_MAX,max(left.size,right.size));
    }
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root) {
        // Your code here
        NodeValue x=solve(root);
        return x.size;
        
    }
};