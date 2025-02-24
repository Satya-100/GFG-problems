//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
    void visPaths(int m, int n, string ds, vector<vector<int>> mat, vector<string>& res, vector<vector<int>>& vis){
        if(m==mat.size()-1 && n==mat.size()-1){
            res.push_back(ds);
            return ;
        }
        
        int dx[4] = {-1, 0, 0, 1};
        int dy[4] = {0, -1, 1, 0};
        string dir = "ULRD";
        
        for(int i=0;i<4;i++){
            int x=m+dx[i];
            int y=n+dy[i];
            if(x>=0 && y>=0 && x<mat.size() && y<mat.size() && !vis[x][y] && mat[x][y]==1){
                vis[x][y] = 1;
                visPaths(x, y, ds+dir[i], mat, res, vis);
                vis[x][y] = 0;
            }
        }
        
    }
    
  public:
    vector<string> findPath(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        vector<string> res;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        vis[0][0]=1;
        
        if(mat[0][0]==1)    visPaths(0, 0, "", mat, res, vis);
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        vector<string> result = obj.findPath(mat);
        sort(result.begin(), result.end());

        if (result.empty())
            cout << "[]";
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends