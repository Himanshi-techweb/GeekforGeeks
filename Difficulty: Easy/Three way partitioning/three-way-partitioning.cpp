class Solution {
  public:
    // Function to partition the array around the range such
    // that array is divided into three parts.
    void threeWayPartition(vector<int>& arr, int a, int b) {
        // code here
        vector<int> less;
        vector<int> great;
        vector<int> range;
        if(a>b)swap(a,b);
        for(int i=0;i<arr.size();i++){
            if(arr[i]<a)less.push_back(arr[i]);
            else if(arr[i]>=a && arr[i]<=b)range.push_back(arr[i]);
            else great.push_back(arr[i]);
        }
        arr.clear();
        for(int i=0;i<less.size();i++)arr.push_back(less[i]);
        for(int i=0;i<range.size();i++)arr.push_back(range[i]);
        for(int i=0;i<great.size();i++)arr.push_back(great[i]);
        // for(auto t:arr)cout<<t<<" ";

    }
};