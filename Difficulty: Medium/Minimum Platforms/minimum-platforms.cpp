class Solution {
  public:

    int minPlatform(vector<int>& s, vector<int>& e) {
        // code here
        int ans=0;int platform=0;
        sort(s.begin(),s.end());
        sort(e.begin(),e.end());
        int i=0;int j=0;
        while(j<s.size() && i<s.size()){
            if(s[i]<=e[j]){
                platform++;
                ans=max(ans,platform);
                i++;
            }
            else {
                platform--;
                j++;
            }
        }
        return ans;
        
    }
};
