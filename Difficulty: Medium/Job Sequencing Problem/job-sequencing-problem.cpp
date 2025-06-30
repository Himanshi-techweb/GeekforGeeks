
class Solution {
  public:
    vector<int> parent;
    int find(int node){
        if(parent[node]==node)return node;
        return parent[node]=find(parent[node]);
    }
    void merge(int u,int v){
        parent[u]=v;
    }
    vector<int> jobSequencing(vector<int> &line, vector<int> &profit) {
        // code here
       int maxi=*max_element(line.begin(),line.end());;
       parent.resize(maxi+1);
       for(int i=0;i<=maxi;i++)parent[i]=i;
       vector<tuple<int,int,int>> check;
       for(int i=0;i<profit.size();i++){
           check.push_back(make_tuple(profit[i],line[i],i));
           
       }
       sort(check.begin(),check.end(),[](auto &a,auto &b){
           return get<0>(a)>get<0>(b);
       });
       int cnt=0;int maxprofit=0;
       for(int i=0;i<check.size();i++){
           int p=get<0>(check[i]);
           int c=get<1>(check[i]);
           int ix=get<2>(check[i]);
           int availableslot=find(c);
           if(availableslot>0){
               merge(availableslot,availableslot-1);
               maxprofit=maxprofit+p;
               cnt++;
           }
       }
       return {cnt,maxprofit};
    }
};