class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // code here
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        vector<int> an;
        int i=0;int j=0;
        while(i<a.size() && j<b.size()){
            // int q=a[i];int r=b[j];
            if(an.size()>0 && a[i]==an.back()){
                i++;continue;
            }
            else if(an.size()>0 && b[j]==an.back()){
                j++;continue;
            }
            if(a[i]<b[j]){
                an.push_back(a[i]);
                i++;
            }
            else if(a[i]>b[j]){
                an.push_back(b[j]);
                j++;
            }
            else{
                an.push_back(a[i]);
                i++;j++;
            }
        }
        while(i<a.size()){
            if(a[i]==an.back()){
                i++;
            }else{
                an.push_back(a[i]);i++;
            }
            
        }
        while(j<b.size()){
            if(b[j]==an.back())j++;
            else{
             an.push_back(b[j]);j++;   
            }
        }
        return an;
    }
};