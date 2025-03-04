//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
    int F(int num){
        int sum=0;
        for(int i=1;i<=num;i++){
            if(num%i==0){
                sum+=i;
            }
        }
        return sum;
    }
    
  public:
    int sumOfDivisors(int n) {
        // Write Your Code here
        int res=0;
        for(int i=1;i<=n;i++){
            res+=F(i);
        }
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        int ans = ob.sumOfDivisors(N);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends