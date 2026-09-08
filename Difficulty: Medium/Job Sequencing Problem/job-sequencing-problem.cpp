class Solution {
  public:
    static bool comparator(vector<int> &a,vector<int>&b){
        return a[0]>b[0];
    }
    int find(vector<int> &x,int y){
        if(x[y]==y)return y;
        return x[y]=find(x,x[y]);
    }
    vector<int> jobSequencing(vector<int> &ti, vector<int> &profit) {
        // code here
        vector<vector<int>> arr;
        int maxi=0;
        for(int i=0;i<profit.size();i++){
            arr.push_back({profit[i],ti[i],i});
            maxi=max(maxi,ti[i]);
        }
        sort(arr.begin(),arr.end(),comparator);
        vector<int> parent(maxi+1);
        for(int i=0;i<maxi+1;i++)parent[i]=i;
        maxi=0;int cnt=0;
        int i=0;
        while(i<arr.size()){
            int slot=find(parent,arr[i][1]);
            if(slot>0){
                maxi+=arr[i][0];
                cnt++;
                parent[slot]=find(parent,slot-1);
            }
            i++;
        }
        
        return {cnt,maxi};
        
    }
};