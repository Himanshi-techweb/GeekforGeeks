class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &arr) {
        // code here
        if(arr.size()==1 && arr[0].size()==1)return {arr[0][0]};
        int frow=0;int lrow=arr.size()-1;
        int fcol=0;int lcol=arr[0].size()-1;
        vector<int> ans;
        while(frow<=lrow && fcol<=lcol){
            // top row traversal 
            for(int j=fcol;j<=lcol;j++){
              if(arr[frow][j]!=-1){
              ans.push_back(arr[frow][j]);
              arr[frow][j]=-1;
              }
            }
            frow++;
            //right column traversal
            for(int i=frow;i<=lrow;i++){
                if(arr[i][lcol]!=-1){
                   ans.push_back(arr[i][lcol]);
                   arr[i][lcol]=-1 ;
                }
            }
            lcol--;
            //bottom row traversal
            for(int j=lcol;j>=fcol;j--){
                if(arr[lrow][j]!=-1){
                    ans.push_back(arr[lrow][j]);
                    arr[lrow][j]=-1;
                }
            }
            lrow--;
            //left column traveral
            for(int i=lrow;i>=frow;i--){
                if(arr[i][fcol]!=-1){
                    ans.push_back(arr[i][fcol]);
                    arr[i][fcol]=-1;
                }
            }
            fcol++;
        }
        return ans;
    }
};