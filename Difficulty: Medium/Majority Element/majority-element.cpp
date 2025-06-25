class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // code here
        int cnt=1;int el=arr[0];
        for(int i=1;i<arr.size();i++){
          if(cnt==0)el=arr[i];
          if(arr[i]==el)cnt++;
          else cnt--;
        }
        if(cnt<=0)return -1;
        int x=arr.size();
        x=x/2;cnt=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==el)cnt++;
        }
        if(cnt>x)return el;
        return -1;
    }
};