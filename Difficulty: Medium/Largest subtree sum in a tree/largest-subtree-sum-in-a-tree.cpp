// User function Template for C++

class Solution {
  public:
    int ans=INT_MIN;
    int solve(Node* root,int sum){
        if(root==NULL)return 0;
        int leftsum=solve(root->left,sum);
        int rightsum=solve(root->right,sum);
        int curr=root->data+leftsum+rightsum;
        ans=max(ans,curr);
        return curr;
    }
    // Function to find largest subtree sum.
    int findLargestSubtreeSum(Node* root) {
        // Write your code here
        int sum=0;
        solve(root,sum);
        return ans;
    }
};
