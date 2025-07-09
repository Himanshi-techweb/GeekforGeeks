class Solution {
  public:
    vector<int> intersection(vector<int> &a,vector<int>&b){
        vector<int> ans;
        int i=0;int j=0;
        while(i<a.size() && j<b.size()){
            if(a[i]==b[j]){
                ans.push_back(a[i]);
                int k=a[i];
                while(i<a.size() && a[i]==k)i++;
                while(j<b.size() && b[j]==k)j++;
            }
            else if(a[i]<b[j])i++;
            else j++;
        }
        return ans;
    }
    // Function to find common elements in three arrays.
    vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,
                               vector<int> &arr3) {
        // Code Here
        vector<int> arr=intersection(arr1,arr2);
        vector<int> ans=intersection(arr3,arr);
        if(ans.size()==0)return {-1};
        else return ans;
    }
};