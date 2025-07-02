class Solution {
  public:
    // Function to return a list containing the intersection of two arrays.
    vector<int> intersection(vector<int> &a, vector<int> &b) {
        // Your code here
        int i=0;int j=0;
        vector<int> ans;
        while(i<a.size() && j<b.size()){
            if(a[i]<b[j])i++;
            else if(b[j]<a[i])j++;
            else {
                if(ans.size() ==0 || ans.back()!=a[i]){
                    ans.push_back(a[i]);
                    
                }i++;j++;
            }
        }
        return ans;
    }
};