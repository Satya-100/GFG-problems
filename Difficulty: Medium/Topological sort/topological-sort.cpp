//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    void dfs(int i, vector<vector<int>>& adj, vector<int>& vis, stack<int>& st){
        vis[i]=1;
        for(int it: adj[i]){
            if(!vis[it]){
                dfs(it, adj, vis, st);
            }
        }
        st.push(i);
    }
  public:
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int> vis(n, 0);
        stack<int> st;
        for(int i=0;i<n;i++){
            if(!vis[i]) dfs(i, adj, vis, st);
        }
        
        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        return res;
        
        
        // Your code here
        // int n = adj.size();
        // vector<int> indegree(n, 0);
        // for(int i=0;i<n;i++){
        //     for(int j: adj[i]){
        //         indegree[j]++;
        //     }
        // }
        // vector<int> res;
        // queue<int> q;
        // for(int i=0;i<n;i++){
        //     if(indegree[i]==0)  q.push(i);
        // }
        // while(!q.empty()){
        //     int node = q.front();
        //     q.pop();
        //     res.push_back(node);
        //     for(int i: adj[node]){
        //         indegree[i]--;
        //         if(indegree[i]==0)  q.push(i);
        //     }
        // }
        // return res;
    }
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
 *   contains the elements in topological sorted form
 *   V: number of vertices
 *   *res: array containing elements in topological sorted form
 *   adj[]: graph input
 */
int check(int V, vector<int> &res, vector<vector<int>> adj) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;
        int u, v;

        vector<vector<int>> adj(N);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topologicalSort(adj);

        cout << check(N, res, adj) << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends