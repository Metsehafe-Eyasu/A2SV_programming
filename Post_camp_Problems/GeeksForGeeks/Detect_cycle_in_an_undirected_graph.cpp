//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool dfs(int currNode, int parent, vector<int> graph[], vector<bool>&visited) {
        if (visited[currNode]) return false;
        visited[currNode] = true;
        for(auto&a : graph[currNode]) {
            if (a == parent) continue;
            if (!dfs(a, currNode, graph, visited)) return false;
        }
        return true;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool>visited(V, false);
        for(int i = 0; i < V; i++) {
            if (!visited[i] && !dfs(i, -1, adj, visited)) return true;
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends