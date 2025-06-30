class interval{
    public:
    int start;
    int end;
    int i;
   interval(int s,int e,int ix){
       start=s;
       end=e;
       i=ix;
   } 
   
};
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        vector<interval> arr;
        for(int i=0;i<start.size();i++){
            arr.push_back(interval(start[i],end[i],i));
        }
        sort(arr.begin(),arr.end(),[](const interval &a,const interval &b){
            return a.end<b.end;
        });
        int cnt=1;int fr=arr[0].end;
        for(int i=1;i<arr.size();i++){
            if(arr[i].start>fr){
              cnt++;
              fr=arr[i].end;
            }
        }
        return cnt;
    }
};