class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // code here
        int major=arr[0];int cnt=1;
        for(int i=1;i<arr.size();i++){
            if(cnt==0){
                    major=arr[i];
            }
            if(arr[i]==major){
                cnt++;
            }
            else{
                cnt--;
                
            }
        }
        if(cnt==0)return -1;
        else{
            cnt=0;
            for(int i=0;i<arr.size();i++){
               if(arr[i]==major)cnt++; 
            }
            if(cnt>(arr.size()/2))return major;
        }
        return -1;    
        
    }
};