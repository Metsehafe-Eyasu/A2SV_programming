//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        vector<int> minimumTime(int n,vector<vector<int>> &edges,int m)
        {
            vector<vector<int>> graph(n+1);
            vector<int>indegree(n+1, 0), ans(n);
            for(auto& pi: edges) {
                graph[pi[0]].push_back(pi[1]);
                indegree[pi[1]]++;
            }
            queue<int>q;
            for (int i = 1; i <= n; i++)
                if (indegree[i] == 0)
                    q.push(i);
            int level = 1;
            while (!q.empty()) {
                int len = q.size();
                for(int _ = 0; _ < len; _++) {
                    int curr = q.front();
                    q.pop();
                    ans[curr-1] = level;
                    for(auto&a: graph[curr]) {
                        indegree[a]--;
                        if (indegree[a] == 0)
                            q.push(a);
                    }
                }
                level++;
            }
            return ans;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int m;
        cin>>m;
        vector<vector<int>> edges(m,vector<int>(2));
        for(int i=0;i<m;i++)
            cin>>edges[i][0]>>edges[i][1];
        Solution s;
        vector<int> ans=s.minimumTime(n,edges,m);
        for(auto j:ans)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends