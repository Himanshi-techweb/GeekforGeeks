class Solution {
  public:
    static bool comparator(vector<int> &a,vector<int> &b){
        if(a[1]!=b[1])return a[1]<b[1];
        return a[2]<b[2];
    }
    
    vector<int> maxMeetings(vector<int> &s, vector<int> &f) {
        // code here
        vector<vector<int>> arr;
        for(int i=0;i<s.size();i++){
            arr.push_back({s[i],f[i],i+1});
        }
        sort(arr.begin(),arr.end(),comparator);
        int cnt=0;int i=0;
        vector<int> ans;int before=-1;
        while(i<arr.size()){
            if(arr[i][0]>before){
                ans.push_back(arr[i][2]);
                before=arr[i][1];
            }
            i++;
        }
    sort(ans.begin(),ans.end());
    return ans;
        
    }
};