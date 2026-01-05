class Solution {
  public:
    vector<int> getMinMax(vector<int> &arr) {
        // code here
        int mini=INT_MAX;
        int maxi=INT_MIN;
        vector<int> a;
        for(auto x:arr){
            if(x>maxi)maxi=x;
            if(x<mini)mini=x;
        }
        a.push_back(mini);
        a.push_back(maxi);
        return a;
    }
};