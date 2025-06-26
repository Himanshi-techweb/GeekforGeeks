
class Solution {
  public:
    void transpose(vector<vector<int>>&arr){
        
    }
    // Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int>>& arr) {
        // code here
        for(int i=0;i<arr.size();i++){
            reverse(arr[i].begin(),arr[i].end());
        }
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr.size();j++){
                if(i<j)swap(arr[i][j],arr[j][i]);
            }
        }
        
    }
};
