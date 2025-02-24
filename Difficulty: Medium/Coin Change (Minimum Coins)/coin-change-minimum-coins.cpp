//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    int f(int ind, vector<int> coins, int sum, vector<vector<int>>& dp){
        if(sum==0)  return 0;
        if(sum<0 || ind==coins.size())  return INT_MAX;
        if(dp[ind][sum]!=-1)    return dp[ind][sum];
        
        int notTake = f(ind+1, coins, sum, dp);
        int take=INT_MAX;
        if(coins[ind]<=sum && coins[ind]>0){
            take = f(ind, coins, sum-coins[ind], dp);
            if(take!=INT_MAX)   take++;
        }
        
        return dp[ind][sum] = min(notTake, take);
    }

  public:
    int minCoins(vector<int> &coins, int sum) {
        // Your code goes here
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        int res = f(0, coins, sum, dp);
        return res!=INT_MAX?res:-1;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minCoins(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends