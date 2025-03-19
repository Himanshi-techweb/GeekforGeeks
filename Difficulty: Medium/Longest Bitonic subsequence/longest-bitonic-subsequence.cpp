//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends


class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &arr) {
        // code here
        // int n=arr.size();
        vector<int> dp1(n,1);
        vector<int> dp2(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i]>arr[j]){
                    dp1[i]=max(dp1[i],1+dp1[j]);
                }
            }
        }
        for(int i=n-2;i>=0;i--){
            for(int j=n-1;j>i;j--){
                if(arr[i]>arr[j]){
                    dp2[i]=max(dp2[i],1+dp2[j]);
                }
            }
        }
        //check if not strictly increasing or strictly decreasing
        // if(*max_element(dp1.begin(),dp1.end())==n || *max_element(dp2.begin(),dp2.end())==n){
        //     return 0;
        // }
        int ans=0;bool check=false;
        for(int i=0;i<n;i++){
          if(dp1[i]>1 && dp2[i]>1){
            ans=max(ans,dp1[i]+dp2[i]-1);  
            check=true;
          }
          
        }return check?ans:0;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> nums(n);
        Array::input(nums, n);

        Solution obj;
        int res = obj.LongestBitonicSequence(n, nums);

        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends