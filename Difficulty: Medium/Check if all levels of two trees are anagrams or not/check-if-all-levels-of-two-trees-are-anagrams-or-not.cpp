// User function Template for C++

class Solution {
  public:
    bool areAnagrams(Node *root1, Node *root2) {
        queue<Node*> q1;
        queue<Node*> q2;
        if(root1->data!=root2->data)return false;
        q1.push(root1);q2.push(root2);
        while(!q1.empty() && !q2.empty()){
            int size1=q1.size(); int size2=q2.size();
            if(size1!=size2)return false;
            vector<int> arr1;
            vector<int> arr2;
            for(int i=0;i<size1;i++){
                Node* front1=q1.front();
                q1.pop();
                Node* front2=q2.front();
                q2.pop();
                arr1.push_back(front1->data);arr2.push_back(front2->data);
                if(front1->left)q1.push(front1->left);
                if(front1->right)q1.push(front1->right);
                if(front2->left)q2.push(front2->left);
                if(front2->right)q2.push(front2->right);
            }
            sort(arr1.begin(),arr1.end());
            sort(arr2.begin(),arr2.end());
            for(int i=0;i<arr1.size();i++){
                if(arr1[i]!=arr2[i])return false;
            }
        }
        return true;
    }
};