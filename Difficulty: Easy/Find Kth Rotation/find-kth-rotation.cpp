class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int ans=INT_MAX;
        int l=0;
        int h=arr.size()-1;
        int t=0;
        while(l<=h){
            int m=(l+h)/2;
            //left sort
            if(arr[l]<=arr[m]){
                if(ans>arr[l]){
                    ans=arr[l];
                    t=l;
                }
                l++;

            }
            //right sort
            else if(arr[m]<=arr[h]){
                if(ans>arr[m]){
                    ans=arr[m];
                    t=m;
                }
                h--;

            }
        }
        return t;
    }
};
