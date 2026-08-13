/* Node Structure
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
    vector<int> leftside(Node* root){
        if(root==NULL || root->left==NULL)return {};
        Node* curr=root->left;
        vector<int> l;
        while(curr){
           
           if(curr->left==NULL && curr->right==NULL)break;
           l.push_back(curr->data);
           if(curr->left)curr=curr->left;
           else curr=curr->right;
        }
        return l;
    }
    vector<int> rightside(Node* root){
        if(root==NULL || root->right==NULL )return {};
        Node* curr=root->right;
        vector<int> r;
        while(curr){
           
           if(curr->left==NULL && curr->right==NULL)break;
           r.push_back(curr->data);
           if(curr->right)curr=curr->right;
           else curr=curr->left;
           
        }
        reverse(r.begin(),r.end());
        // r.pop_back();
        return r;
    }
    vector<int> leaf;
    void in(Node* root){
        
        if(root==NULL )return;
        in(root->left);
        if(root->left==NULL && root->right==NULL){
            leaf.push_back(root->data);
            return;
        }
        in(root->right);
        
    }
    // vector<int> leafside(Node* root){
    //     if(root==NULL)return {};
    //     vector<int>leaf;
    //     Node* curr=root;
    //     while(curr){
    //         if(curr->left==NULL && curr->right==NULL){
                
    //         }
    //     }
    // }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        if(root==NULL)return {};
        vector<int>ans;
        if(root->left==NULL && root->right==NULL)return {root->data};
        ans.push_back(root->data);
        vector<int>l=leftside(root);
        vector<int>r=rightside(root);
        in(root);
        ans.insert(ans.end(),l.begin(),l.end());
        ans.insert(ans.end(),leaf.begin(),leaf.end());
        ans.insert(ans.end(),r.begin(),r.end());
        return ans;
        
    }
};