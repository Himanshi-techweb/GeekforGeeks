class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& arr) {
        // Your code goes here.
        int cnt1=0;int el1=0;
        int cnt2=0;int el2=0;
        for(int i=0;i<arr.size();i++){
            if(cnt1==0 && arr[i]!=el2){
                el1=arr[i];cnt1++;
            }
            else if(cnt2==0 && arr[i]!=el1){
                el2=arr[i];
                cnt2++;
            }
            else if(el1==arr[i])cnt1++;
            else if(el2==arr[i])cnt2++;
            else {
                cnt1--;cnt2--;
            }
        }
        vector<int> ans;
        int n=arr.size();
        if(cnt1>0){
          int check1=0;  
          for(int i=0;i<arr.size();i++){
              if(arr[i]==el1)check1++;
          }
          if(check1> (ceil(n/3)))ans.push_back(el1);
        }
        
        if(cnt2>0){
          int check2=0; 
          for(int i=0;i<arr.size();i++){
              if(arr[i]==el2)check2++;
          }
          if(check2> (ceil(n/3)))ans.push_back(el2);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};