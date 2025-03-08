//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends



class Solution{
	public:
	bool isprime(int n){
	    if(n<2)return false;
	    if(n==2 || n==3)return true;
	    if(n%2==0 || n%3==0)return false;
	    for(int i=3;i*i<=n;i+=1){
	       if(n%i==0)return false;
	    }return true;
	}
	vector<int>AllPrimeFactors(int N) {
        unordered_set<int> st;
        int x=sqrt(N);
        for(int i=1;i<=N;i++){
            if(N%i==0 && isprime(i)){
                st.insert(i);
            }
        }
        vector<int> ans;
        for(auto i=st.begin();i!=st.end();i++){
            // int y=*i;
            ans.push_back(*i);
        }
        sort(ans.begin(),ans.end());
        return ans;
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int N;
		cin >> N;
		Solution ob;
		vector<int>ans = ob.AllPrimeFactors(N);
		for(auto i: ans)
			cout << i <<" ";
		cout <<"\n";
	
cout << "~" << "\n";
}  
	return 0;
}
// } Driver Code Ends