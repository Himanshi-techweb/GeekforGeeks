class Solution {
  public:
    // Function to find common elements in three arrays.
    vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,
                               vector<int> &arr3) {
        // Code Here
        int i=0;int j=0;int k=0;
        vector<int> ans;
        int a=arr1.size();int b=arr2.size();int c=arr3.size();
        while(i<a && j<b && k<c){
            if(arr1[i]==arr2[j] && arr1[i]==arr3[k]){
              int x=arr1[i];
              ans.push_back(x);
              while(i<a && arr1[i]==x)i++;
              while(j<b && arr2[j]==x)j++;
              while(k<c && arr3[k]==x)k++;
            }
            else{
                int mini=min({arr1[i],arr2[j],arr3[k]});
                if(arr1[i]==mini)i++;
                if(arr2[j]==mini)j++;
                if(arr3[k]==mini)k++;
                
            }
        }
        return ans;
    }
};