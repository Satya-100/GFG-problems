//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> JobSequencing(vector<int> &id, vector<int> &deadline,
                              vector<int> &profit) {
        // code here
        vector<pair<int, int>> arr;
        int maxDeadline=INT_MIN;
        int n=deadline.size();
        for(int i=0;i<n;i++){
            arr.push_back({profit[i], deadline[i]});
            maxDeadline=max(maxDeadline, deadline[i]);
        }
        
        sort(arr.begin(), arr.end(), [](pair<int, int> a, pair<int, int> b){ return a.first>b.first;});
        
        vector<int> dead(maxDeadline, -1);
        int cnt=0;
        int maxProfit=0;
        
        for(int i=0;i<n;i++){
            for(int j=arr[i].second-1;j>=0;j--){
                if(dead[j]==-1){
                    dead[j]=arr[i].first;
                    cnt++;
                    maxProfit+=arr[i].first;
                    break;
                }
            }
        }
        return {cnt, maxProfit};
    }
};


//{ Driver Code Starts.
//            Driver program to test methods
int main() {
    int t;
    // testcases
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> jobIDs, deadlines, profits;
        string temp;
        getline(cin, temp);
        istringstream ss1(temp);
        int x;
        while (ss1 >> x)
            jobIDs.push_back(x);

        getline(cin, temp);
        istringstream ss2(temp);
        while (ss2 >> x)
            deadlines.push_back(x);

        getline(cin, temp);
        istringstream ss3(temp);
        while (ss3 >> x)
            profits.push_back(x);

        int n = jobIDs.size();

        Solution obj;
        vector<int> ans = obj.JobSequencing(jobIDs, deadlines, profits);
        cout << ans[0] << " " << ans[1] << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends