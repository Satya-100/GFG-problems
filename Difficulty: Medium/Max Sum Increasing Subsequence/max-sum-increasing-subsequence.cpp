//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    int f(vector<int> arr, int i, vector<int>& dp){
        if(dp[i]!=-1)    return dp[i];
        int ans = arr[i];
        
        for(int j=i-1;j>=0;j--){
            if(arr[j]<arr[i]){
                ans = max(ans, arr[i] + f(arr, j, dp));
            }
        }
        
        return dp[i] = ans;
    }
    
  public:
    int maxSumIS(vector<int>& arr) {
        // Your code goes here
        int n=arr.size();
        int res=INT_MIN;
        vector<int> dp(n, -1);
        
        for(int i=0;i<n;i++){
            res = max(res, f(arr, i, dp));
        }
        
        return res;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.maxSumIS(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends