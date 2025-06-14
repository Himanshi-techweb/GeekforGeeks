class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // int n1=a.size();int n2=b.size();
        // // code here
        // int cnt=0;
        // int i=0;int j=0;
        // while(i<n1 && j<n2){
        //     if(a[i]<b[j]){
        //         cnt++;
        //         if(cnt==k)return a[i];
        //         i++;
        //     }
        //     else{
        //       cnt++;
        //       if(cnt==k)return b[j];
        //       j++;
        //     }
        // }
        // while(i<n1){
        //         cnt++;
        //         if(cnt==k)return a[i];
        //         i++;
        // }
        // while(j<n2){
        //       cnt++;
        //       if(cnt==k)return b[j];
        //       j++;
        // }
        // return 0;
        
        
        
        
        
        int x1=a.size();
        int x2=b.size();
        if(x1>x2)return kthElement(b,a,k);
        int low=max(0,k-x2);
        int high=min(k,x1);
        int left=k;
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
                    return max(l1,l2);
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




















