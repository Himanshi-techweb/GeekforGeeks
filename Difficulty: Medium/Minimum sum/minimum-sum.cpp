class Solution {
  public:
    // string minSum(vector<int> &arr) {
    //     // code here
    //     priority_queue<int,vector<int>,greater<int>> q;
    //     for(auto it:arr)q.push(it);
    //     int a_count=0;int b_count=0;int a=0;int b=0;
    //     while(!q.empty()){
    //       int fr=q.top();q.pop();
    //       if(a_count==b_count){
    //           a=a*10 +fr;a_count++;
    //       }
    //       else if(a_count>b_count){
    //          b=b*10 +fr;b_count++;  
    //       }
    //       else{
    //          a=a*10 +fr;a_count++;
    //       }
    //     }
    //     int ans=a+b;
    //     return to_string(a+b);
    // }
    string addStrings(string a, string b) {
    string result = "";
    int i = a.size() - 1, j = b.size() - 1, carry = 0;
    
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        carry = sum / 10;
        result += (sum % 10) + '0';
    }

    reverse(result.begin(), result.end());

    // ✅ Remove leading zeros
    int start = 0;
    while (start < result.size() - 1 && result[start] == '0') {
        start++;
    }
    return result.substr(start);
}
string minSum(vector<int>& arr) {
    priority_queue<int, vector<int>, greater<int>> q;
    for (int d : arr) q.push(d);

    string a = "", b = "";
    int a_count = 0, b_count = 0;

    while (!q.empty()) {
        int digit = q.top(); q.pop();
        if (a_count <= b_count) {
            a += (digit + '0');
            a_count++;
        } else {
            b += (digit + '0');
            b_count++;
        }
    }

    return addStrings(a, b);
}

};