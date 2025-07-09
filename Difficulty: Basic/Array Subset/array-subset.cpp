class Solution {
  public:
    // Function to check if b is a subset of a
    bool isSubset(vector<int> &a, vector<int> &b) {
        // Your code here
        unordered_map<int,int> check;
        for(auto it:a)check[it]++;
        for(auto it:b){
            if(check.find(it)!=check.end()){
                check[it]--;
                if(check[it]==0)check.erase(it);
            }
            else return false;
        }
        return true;
    }
};