//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find minimum number of attempts needed in
    // order to find the critical floor.
    int eggDrop(int n, int k) {
        // your code here
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
        
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
            dp[i][1]=1;
        }
        
        for(int i=1;i<=k;i++){
            dp[1][i]=i;
        }
        
        int res;
        
        for(int i=2;i<=n;i++){
            for(int j=2;j<=k;j++){
                dp[i][j]=INT_MAX;
                for(int k=1;k<=j;k++){
                    res = 1 + max(dp[i-1][k-1], dp[i][j-k]);
                    dp[i][j]=min(res, dp[i][j]);
                }
            }
        }
        
        return dp[n][k];
    }
};

//{ Driver Code Starts.
int main() {
    // taking total testcases
    int t;
    cin >> t;
    while (t--) {
        // taking eggs and floors count
        int n, k;
        cin >> n >> k;
        Solution ob;
        // calling function eggDrop()
        cout << ob.eggDrop(n, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends