class Solution {
  public:
    int smallestSubWithSum(int x, vector<int>& arr) {
        // Your code goes here
        int i=0;int j=0;
        int sum=0;int minlen=INT_MAX;
        while(j<arr.size()){
            sum+=arr[j];
            if(sum>x){
                while(sum>x){
                    sum-=arr[i];i++;
                }
                minlen=min(j-i+2,minlen);
            }
            j++;
        }
        return (minlen!=INT_MAX)?minlen:0;
    }
};