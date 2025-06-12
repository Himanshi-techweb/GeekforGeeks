/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
     map<int,int > check;// vertical ,level ,node
     queue<pair<Node*,int>> q;//node,vertical,level
     vector<int> ans;
     q.push({root,0});
     while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size ;i++){
            auto w=q.front();
            q.pop();
            Node* node=w.first;
            int c=w.second;
            //int h=w.second.second;
            if(check.find(c)==check.end())check[c]=(node->data);
            if(node->left){
                q.push({node->left,c-1});
            }
            if(node->right){
                q.push({node->right,c+1});
            }
        }
     }
     for(auto i:check){
       ans.push_back(i.second);
     }
     return ans;   
    }
};