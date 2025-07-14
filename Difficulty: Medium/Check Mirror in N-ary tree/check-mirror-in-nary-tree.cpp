// User function Template for C++

class Solution {
  public:
    int checkMirrorTree(int n, int e, int a[], int b[]) {
        // code here
        unordered_map<int,vector<int>> check_a;
        unordered_map<int,vector<int>> check_b;
        for(int i=0;i<2*e;i=i+2){
            check_a[a[i]].push_back(a[i+1]);
        }
        for(int i=0;i<2*e;i=i+2){
            check_b[b[i]].push_back(b[i+1]);
        }
        if(check_a.size()!=check_b.size())return false;
        for(auto it:check_a){
            if(check_b.find(it.first)==check_b.end())return false;
            vector<int> check1=it.second;
            vector<int> check2=check_b[it.first];
            vector<int> reverse_copy=check2;
            reverse(reverse_copy.begin(),reverse_copy.end());
            if(check1!=reverse_copy)return false;
        }
        return true;
    }
};