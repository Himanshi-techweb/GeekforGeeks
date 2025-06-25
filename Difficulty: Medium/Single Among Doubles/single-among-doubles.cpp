// User function template for C++
class Solution {
  public:
    int search(int n, int a[]) {
        // code
        int left=0;
        int right=n-1;
        while(left<right){
            int mid=(left+right)/2;
            if(a[mid]!=a[mid-1] && a[mid]!=a[mid+1])return a[mid];
            if(a[mid]==a[mid-1] && mid%2==1){
                left=mid+1;
            }
            else if(a[mid]==a[mid-1] && mid%2==0)right=mid-1;
            else if(a[mid]==a[mid+1] && mid%2==1)right=mid-1;
            else left=mid+1;
        }
        return a[right];
    }
};