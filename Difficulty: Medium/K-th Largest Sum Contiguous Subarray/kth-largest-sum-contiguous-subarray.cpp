// User function Template for C++

class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        // code here
        priority_queue<int>q;int sum=0;
        for(int i=0;i<arr.size();i++){
            sum=0;
            for(int j=i;j<arr.size();j++){
               sum=sum+arr[j];
               q.push(sum);
            }
        }int i=k;
        while(!q.empty() && i>1){
           q.pop();i--; 
        }
        return q.top();
    }
};