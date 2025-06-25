class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        vector<int> ans;
        int i=0;int j=0;int k=0;
        ans.push_back(INT_MIN);
        while(i<a.size() && j<b.size()){
           if(a[i]<b[j] && (ans.back()==INT_MIN || ans.back()!=a[i])){
               ans.push_back(a[i]);
               i++;
           }
           else if(a[i]>b[j] && (ans.back()==INT_MIN || ans.back()!=b[j])){
               ans.push_back(b[j]);
               j++;
           }
           else if(a[i]==b[j] && ans.back()!=a[i]){
               ans.push_back(a[i]);
               i++;j++;
           }
           else{
                if(ans.back()==a[i])i++;
                if(ans.back()==b[j])j++; 
           }
           
        }
        while(i<a.size()){
            if(ans.back()!=a[i]){
                ans.push_back(a[i]);
            }
            i++;
        }
        while(j<b.size()){
            if(ans.back()!=b[j]){
                ans.push_back(b[j]);
            }
            j++;
        }
        return vector<int>(ans.begin()+1,ans.end());
        // return vector with correct order of elements
    }
};