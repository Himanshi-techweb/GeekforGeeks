class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int fmini=arr[0];
        int smini=-1;
        for(int i=1;i<arr.size();i++){
            if(fmini<arr[i] ){
                smini=fmini;
                fmini=arr[i];
            }
            else if(fmini>arr[i] && smini<arr[i])smini=arr[i];
        }
        return smini;
    }
};