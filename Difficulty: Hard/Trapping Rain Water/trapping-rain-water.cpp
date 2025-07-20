class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        vector<int> pge(arr.size());
        pge[0]=arr[0];int cnt=0;
        vector<int> nge(arr.size());
        nge[arr.size()-1]=arr[arr.size()-1];
        for(int i=1;i<arr.size();i++){
           pge[i]=max(pge[i-1],arr[i]); 
        }
        for(int i=arr.size()-2;i>=0;i--){
            nge[i]=max(nge[i+1],arr[i]);
        }
        for(int i=0;i<arr.size();i++){
           cnt+=(min(pge[i],nge[i])-arr[i]); 
        }
        return cnt;
    }
};