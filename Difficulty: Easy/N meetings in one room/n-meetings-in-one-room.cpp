//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
struct Data {
    int start;
    int end;
    int pos;
};

class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int n=start.size();
        Data arr[n];
        for(int i=0;i<n;i++){
            arr[i].start = start[i];
            arr[i].end = end[i];
            arr[i].pos = i;
        }
        
        sort(arr, arr+n, [](Data a, Data b){return a.end<b.end;});
        
        int cnt=1;
        int freeTime = arr[0].end;
        vector<int> ds;
        ds.push_back(arr[0].pos);
        
        for(int i=1;i<n;i++){
            if(arr[i].start>freeTime){
                cnt++;
                freeTime = arr[i].end;
                ds.push_back(arr[i].pos);
            }
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> start;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            start.push_back(num);
        }

        vector<int> end;
        getline(cin, input);
        stringstream s22(input);
        while (s22 >> num) {
            end.push_back(num);
        }

        Solution ob;
        int ans = ob.maxMeetings(start, end);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends