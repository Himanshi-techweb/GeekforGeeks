class Solution {
  public:
    double medianOf2(vector<int>& a, vector<int>& b) {
        // Your code goes here
        int x1=a.size();
        int x2=b.size();
        if(x1>x2)return medianOf2(b,a);
        int low=0;
        int high=x1;
        int left=(x1+x2+1)/2;
        while(low<=high){
            int mid1=low+(high-low)/2;
            int mid2=left-mid1;
            int l1=INT_MIN;int l2=INT_MIN;
            int r1=INT_MAX;int r2=INT_MAX;
            if(mid1>0)l1=a[mid1-1];
            if(mid2>0)l2=b[mid2-1];
            if(mid1<x1)r1=a[mid1];
            if(mid2<x2)r2=b[mid2];
            if(l1<=r2 && l2<=r1){
                if((x1+x2)%2==0){
                    return (double)(max(l1,l2)+min(r1,r2))/2;
                }
                else{
                    return max(l1,l2);
                }
            }
            else if(l1>r2){
                high=mid1-1;
            }
            else{
                low=mid1+1;
            }
        }
        return 0;
    }
};