class Solution {
  public:

    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        // code here
        d=d%arr.size();
        reverse(arr.begin(),arr.end());
        reverse(arr.begin(),arr.begin()+arr.size()-d);
        reverse(arr.begin()+arr.size()-d,arr.end());
    }
};