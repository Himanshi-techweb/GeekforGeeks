class Solution {
  public:
    string nextPermutation(string &arr) {
        int ix=-1;
        for(int i=arr.size()-2;i>=0;i--){
           if(arr[i]-'a'<arr[i+1]-'a'){
            ix=i;break;
           }
        }
        if(ix==-1){
            reverse(arr.begin(),arr.end());
            return arr;
        }
        else{
            for(int i=arr.size()-1;i>ix;i--){
               if(arr[i]-'a'>arr[ix]-'a'){
                swap(arr[i],arr[ix]);
                break;
               }
            }
            reverse(arr.begin()+ix+1,arr.end());
            return arr;
        }
    }
    vector<string> findPermutation(string &s) {
        // Code here there
        vector<string> ans;
        string copy=s;
        string re="";
        while(re!=copy){
            re=nextPermutation(s);
            ans.push_back(re);
            s=re;
        }
        return ans;
    }
};
