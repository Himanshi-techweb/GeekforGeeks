class Solution {
  public:
    int solve1(string &str){
        int num=0;
        for(auto it:str){
            num+=(it-'0');
        }
        return num;
    }
    unordered_map<int,unordered_map<int,int>> dp;
    int solve(int i,int prev,string &s,vector<int> &arr){
       if(i==s.size())return 1;
       if(dp.find(i)!=dp.end() && dp[i].find(prev)!=dp[i].end())return dp[i][prev];
       int res=0;
       string str="";
       for(int k=i;k<s.size();k++){
          
          int num=arr[k+1]-arr[i];
          
        //   int num=stoi(str);
          if(prev<=num){
            //   cout<<prev<<" "<<num<<endl;
              res+=solve(k+1,num,s,arr);
          }
       }
    //   cout<<endl;
       return dp[i][prev]=res;
    }
    int validGroups(string &s) {
        // code here
        vector<int>arr(s.size()+1);
        arr[0]=0;
        for(int i=0;i<s.size();i++){
            arr[i+1]=arr[i]+(s[i]-'0');
        }
        return solve(0,-1,s,arr);
    }
};