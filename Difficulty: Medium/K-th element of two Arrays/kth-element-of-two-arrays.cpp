class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int n1=a.size();int n2=b.size();
        // code here
        int cnt=0;
        int i=0;int j=0;
        while(i<n1 && j<n2){
            if(a[i]<b[j]){
                cnt++;
                if(cnt==k)return a[i];
                i++;
            }
            else{
              cnt++;
              if(cnt==k)return b[j];
              j++;
            }
        }
        while(i<n1){
                cnt++;
                if(cnt==k)return a[i];
                i++;
        }
        while(j<n2){
              cnt++;
              if(cnt==k)return b[j];
              j++;
        }
        return 0;
    }
};