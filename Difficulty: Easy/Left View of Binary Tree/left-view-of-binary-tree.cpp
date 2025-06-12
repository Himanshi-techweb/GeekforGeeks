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
    queue<int> q;
    void right(Node* root,int level){
       if(root==NULL)return;
       if(q.size()==level){
        q.push(root->data);
       }
       right(root->left,level+1);
       right(root->right,level+1);
       
    }
    vector<int> leftView(Node* root) {
        right(root,0);
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};