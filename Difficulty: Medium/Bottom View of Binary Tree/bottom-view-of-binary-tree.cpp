// Function to return a list containing the bottom view of the given tree.

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // Your Code Here
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
            check[c]=(node->data);
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