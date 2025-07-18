class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int i=0;int j=0;int platform=0;int maxplatform=0;
        while(i< arr.size() && j<dep.size()){
            if(arr[i]<=dep[j]){
                platform++;
                i++;
            }
            else{
                platform--;
                j++;
            }
            maxplatform=max(platform,maxplatform);
        }
        return maxplatform;
    }
};
