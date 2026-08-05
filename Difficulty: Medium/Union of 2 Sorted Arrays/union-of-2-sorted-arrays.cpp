class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // code here
        vector<int> ans;
        int i=0;int j=0;
        while(i<a.size() && j<b.size()){
            
            
                if(a[i]<b[j]){
                ans.push_back(a[i]);
                i++;
                }
                else if(a[i]>b[j]){
                ans.push_back(b[j]);
                j++;
                }
                else if(a[i]==b[j]){
                ans.push_back(a[i]);
                i++;
                j++;
                }
            while(ans.size()>0 && ans.back()==a[i])i++;
            while(ans.size()>0 && ans.back()==b[j])j++;
                
            
        }
        while(i<a.size()){
            ans.push_back(a[i]);
            i++;
            while(ans.back()==a[i])i++;
        }
        while(j<b.size()){
            ans.push_back(b[j]);
            j++;
            while(ans.back()==b[j])j++;
        }
        return ans;
    }
};