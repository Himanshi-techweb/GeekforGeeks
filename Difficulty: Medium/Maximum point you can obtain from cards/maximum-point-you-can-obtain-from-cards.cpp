class Solution {
  public:
    int maxScore(vector<int>& cardPoints, int k) {
        // code here.
        int n=cardPoints.size();
        if(k==n)return accumulate(cardPoints.begin(),cardPoints.end(),0);
        int leftsum=accumulate(cardPoints.begin(),cardPoints.begin()+k,0);
        int rightsum=0;
        int maxsum=max(leftsum+rightsum,maxsum);
        int l=k-1;int r=n-1;
        while(l>=0 && l<=r){
            leftsum-=cardPoints[l];
            rightsum+=cardPoints[r];
            maxsum=max(leftsum+rightsum,maxsum);
            l--;r--;
        }
        return maxsum;
    }
};
