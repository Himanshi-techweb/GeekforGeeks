// User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/
class Solution {
  public:
    //void morris(Node* root,)
    vector<int> inOrder(Node* root) {
        // code here
        if(root==NULL)return {};
        vector<int> in;
        Node* curr=root;
        while(curr){
            if(!curr->left){
                in.push_back(curr->data);
                curr=curr->right;
            }
            else{
                Node* prev=curr->left;
                while(prev->right && prev->right!=curr){
                    prev=prev->right;
                }
                if(prev->right){
                    curr->left=NULL;
                    in.push_back(curr->data);
                    curr=curr->right;
                }
                else{
                   prev->right=curr;
                   curr=curr->left;
                }
            }
        }
        return in;
    }
};