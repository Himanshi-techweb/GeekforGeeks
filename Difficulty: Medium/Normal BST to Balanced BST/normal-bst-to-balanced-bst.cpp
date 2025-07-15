/*Structure of the Node of the BST is as
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
    void inorder(Node* root,vector<int>&in){
        if(root==NULL)return;
        inorder(root->left,in);
        in.push_back(root->data);
        inorder(root->right,in);
    }
    Node* build(vector<int> &arr,int st,int end){
        if(st>end)return NULL;
        int mid=(st+end)/2;
        Node* newnode=new Node(arr[mid]);
        newnode->left=build(arr,st,mid-1);
        newnode->right=build(arr,mid+1,end);
        return newnode;
    }
    Node* balanceBST(Node* root) {
        // Code here
        vector<int> in;
        inorder(root,in);
        return build(in,0,in.size()-1);
    }
};