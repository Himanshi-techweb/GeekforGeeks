class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        // code here
        vector<int> ans;
        int i=arr.size()-1;
        int curr=arr.size()-1;
        int maxi=arr[arr.size()-1];
        while(i>=0){
            if(arr[i]>=arr[curr]){
                maxi=arr[i];
                curr=i;
            } 
            
            if(i==curr)ans.push_back(maxi);
            i--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};