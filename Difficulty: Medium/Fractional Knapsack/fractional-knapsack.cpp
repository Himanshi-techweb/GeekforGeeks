// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int c) {
        // code here
        vector<vector<int>> check;
        for(int i=0;i<wt.size();i++){
            check.push_back({val[i],wt[i]});
        }
        sort(check.begin(),check.end(),[](const auto &a,const auto &b){
            // return (double)a[0]/a[1]>(double)b[0]/b[1];
            return (double)a[0]/a[1]>(double)b[0]/b[1];
        });
        double total=0;
        for(int i=0;i<check.size();i++){
            if(c>=check[i][1]){
                c=c-check[i][1];
                total+=check[i][0];
            }
            else{
                total+=(((double)c/check[i][1])*check[i][0]);
                break;
            }
        }
        return total;
    }
};
