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
    vector<vector<int>> verticalOrder(Node *root) {
        // code here
        vector<vector<int>> ans;
        map<int,vector<int>> st;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            Node* node=front.first;
            int cnt=front.second;
            st[cnt].push_back(node->data);
            if(node->left){
                q.push({node->left,cnt-1});
            }
            if(node->right){
                q.push({node->right,cnt+1});
            }
        }
        for(auto it:st){
            ans.push_back(it.second);
        }
        return ans;
        
        
    }
};