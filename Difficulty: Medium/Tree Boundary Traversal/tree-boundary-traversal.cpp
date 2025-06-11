/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void leftcheck(Node* root,vector<int> &result){
      //vector<int> left;
      Node* curr=root->left;
      while(curr){
        if(curr->left!=NULL || curr->right!=NULL)result.push_back(curr->data);
        if(curr->left)curr=curr->left;
        else curr=curr->right;
      }
      //result.insert(result.end(),left.begin(),left.end());
    }
    void leafcheck(Node* root,vector<int> &result){
        if(root==NULL)return;
      if(root->left==NULL && root->right==NULL)result.push_back(root->data);
      if(root->left)leafcheck(root->left,result);
      if(root->right)leafcheck(root->right,result);
    }
    void rightcheck(Node* root,vector<int> &result){
      vector<int> right;
      Node* curr=root->right;
      while(curr){
        if(curr->left!=NULL || curr->right!=NULL)right.push_back(curr->data);
        if(curr->right)curr=curr->right;
        else curr=curr->left;
      }
      reverse(right.begin(),right.end());
      result.insert(result.end(),right.begin(),right.end()); 
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        if(root==NULL)return {};
        vector<int> result;
        if(root->left!=NULL || root->right!=NULL )result.push_back(root->data);
        leftcheck(root,result);
        leafcheck(root,result);
        rightcheck(root,result);
        return result;
        
    }
};