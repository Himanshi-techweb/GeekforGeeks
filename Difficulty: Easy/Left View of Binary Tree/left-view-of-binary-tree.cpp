/* A binary tree node

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
    // vector<int> leftView(Node *root) {
    //     // code here
        
    // }
    vector<int> ans;
    // queue<int> q;
    void left(Node* root,int level){
       if(root==NULL)return;
       if(ans.size()==level){
       ans.push_back(root->data);
       }
       left(root->left,level+1);
       left(root->right,level+1);
       
    }
    vector<int> leftView(Node* root) {
        left(root,0);
        // while(!q.empty()){
        //     ans.push_back(q.front());
        //     q.pop();
        // }
        return ans;
    }
};