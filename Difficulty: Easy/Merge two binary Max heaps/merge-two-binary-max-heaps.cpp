// User function Template for C++

class Solution {
  public:
    void heapify(vector<int> &arr,int n,int i){
    int largest=i;
    int left=2*i +1;
    int right=2*i +2;
    if(left<n && arr[left]>arr[largest])largest=left;
    if(right<n && arr[right]>arr[largest])largest=right;
    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        vector<int> merge=a;
        merge.insert(merge.end(),b.begin(),b.end());
        int x=n+m;
        for(int i=x/2;i>=0;i--){
            heapify(merge,x,i);
        }
        return merge;
    }
};