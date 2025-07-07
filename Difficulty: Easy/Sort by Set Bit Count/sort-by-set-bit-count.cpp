class compare{
  public:
  bool operator()(const int &a,const int &b)const{
      int cnt_a= __builtin_popcount(a);
      int cnt_b= __builtin_popcount(b);
    //   if(cnt_a==cnt_b)return a<b;
      return cnt_a>cnt_b;
  }  
};
class Solution {
  public:
    void sortBySetBitCount(int arr[], int n) {
        // Your code goes here
        stable_sort(arr,arr+n,compare());
    }
};