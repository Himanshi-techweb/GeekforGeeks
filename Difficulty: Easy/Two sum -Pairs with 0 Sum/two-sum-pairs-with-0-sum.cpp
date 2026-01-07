// User function template for C++

class Solution {
  public:
    vector<vector<int>> getPairs(vector<int>& arr) {
        // code here
        vector<vector<int>> ans;
        unordered_map<int,int> check;
        for(int i=0;i<arr.size();i++){
            check[arr[i]]++;
            
        }
        
        //check case of 0 
        int count=check[0];
            for(int i=0;i<count/2;i++){
                ans.push_back({0,0});
            }
        
        // vector<vector<int>> ans;
        for(int i=0;i<arr.size();i++){
            int x=arr[i];
            if(x==0)continue;
            if(check.find(-x)!=check.end()){
                vector<int> arr1;
                arr1.push_back(x);arr1.push_back(-x);
                
                sort(arr1.begin(),arr1.end());
                ans.push_back(arr1);
                check.erase(x);check.erase(-x);
            }
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};