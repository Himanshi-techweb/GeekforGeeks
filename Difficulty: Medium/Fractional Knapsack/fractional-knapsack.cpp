//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/
//solve it by greedy approach;
class comparator{
  public:
  bool operator()(pair<int,int> a,pair<int,int> b){
     return (double)a.first/a.second>(double)b.first/b.second;
  }
};
class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        vector<pair<int,int>> item;
        for(int i=0;i<wt.size();i++){
            item.push_back({val[i],wt[i]});
        }
        sort(item.begin(),item.end(),comparator());
        double total=0;
        for(int i=0;i<wt.size();i++){
            if(item[i].second<=capacity){
                capacity=capacity-item[i].second;
                total+=item[i].first;
            }
            else{
                total+=(((double)item[i].first/item[i].second)*capacity);
                break;
            }
        }
        return total;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    // taking testcases
    cin >> t;
    cin.ignore(); // to ignore the newline after the number of test cases
    cout << setprecision(6) << fixed;

    while (t--) {
        // Reading the value array
        vector<int> values;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            values.push_back(number);
        }

        // Reading the weight array
        vector<int> weights;
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            weights.push_back(number);
        }

        // Reading the capacity
        int w;
        cin >> w;
        cin.ignore(); // to ignore the newline after capacity

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(values, weights, w) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends