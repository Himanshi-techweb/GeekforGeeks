class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        queue<int> q;
        vector<int> ans;
        //traverse first k element
        for(int i=0;i<k;i++){
            if(arr[i]<0)q.push(arr[i]);
        }
        if(q.empty())ans.push_back(0);
        else ans.push_back(q.front());
        //traverse next element in row
        int i=k;
        while(i<arr.size()){
           if(!q.empty() && q.front()==arr[i-k])q.pop();
           if(arr[i]<0)q.push(arr[i]);
           if(q.empty())ans.push_back(0);
           else ans.push_back(q.front());
           i++;
        }
        return ans;
    }
};