//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    void dfs(int row, int col, vector<vector<int>>& grid, vector<pair<int, int>>& temp, vector<vector<int>>& vis, int nrow, int ncol){
        int m = grid.size();
        int n = grid[0].size();
        vis[row][col]=1;
        temp.push_back({row-nrow, col-ncol});
        
        int crow[] = {-1, 0, 1, 0};
        int ccol[] = {0, -1, 0, 1};
        for(int i=0;i<4;i++){
            int trow = row + crow[i];
            int tcol = col + ccol[i];
            if(trow>=0 && trow<m && trow>=0 && tcol<n && !vis[trow][tcol] && grid[trow][tcol]==1)            dfs(trow, tcol, grid, temp, vis, nrow, ncol);
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int m = grid.size();
        int n = grid[0].size();
        set<vector<pair<int, int>>> st;
        vector<vector<int>> vis(m, vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    vector<pair<int, int>> temp;
                    dfs(i, j, grid, temp, vis, i, j);
                    st.insert(temp);
                }
            }
        }
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends