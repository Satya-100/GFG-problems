//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    bool isSafe(int node, int v, vector<pair<int, int>>& edges, vector<int>& color, int col){
        for(auto it: edges){
            int x = it.first;
            int y = it.second;
            if(x==node && color[y]==col)    return false;
            if(y==node && color[x]==col)    return false;
        }
        return true;
    }
    
    bool solve(int node, int v, vector<pair<int, int>>& edges, int m, vector<int>& color){
        if(node==v) return true;
        
        for(int i=1;i<=m;i++){
            if(isSafe(node, v, edges, color, i)){
                color[node] = i;
                if(solve(node+1, v, edges, m, color))   return true;
                color[node] = 0;
            }
        }
        
        return false;
    }
    
  public:
    bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
        // code here
        vector<int> color(v, 0);
        return solve(0, v, edges, m, color);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m;
        cin >> n;
        cin.ignore(); // Ignore newline after reading n
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number); // Populate the array with edge values
        }
        cin >> m;
        cin.ignore(); // Ignore newline after reading m

        int edges_count = arr.size();
        vector<pair<int, int>> edges(edges_count /
                                     2); // Correct size of the edges vector

        for (int i = 0; i < edges_count; i += 2) {
            int l1 = arr[i];
            int l2 = arr[i + 1];
            edges[i / 2] = {l1, l2}; // Properly assign the pair
        }

        Solution ob;
        cout << (ob.graphColoring(n, edges, m) ? "true" : "false")
             << "\n~\n"; // Call the graph coloring function
    }
    return 0;
}

// } Driver Code Ends