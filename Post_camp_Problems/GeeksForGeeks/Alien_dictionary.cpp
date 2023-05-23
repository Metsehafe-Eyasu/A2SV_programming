//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    bool top_sort(vector<vector<int>>& graph, string& result) {
        vector<int> inDegree(26, 0);
        for(int i = 0; i < 26; i++)
            for(int curr: graph[i]) 
                inDegree[curr]++;
        queue<int>q;
        for(int i = 0; i < 26; i++) 
            if (inDegree[i] == 0)
                q.push(i);
    
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
    
            result.push_back(curr + 'a');
            for(int num: graph[curr])
                if (--inDegree[num] == 0) 
                    q.push(num);
        }
        return result.length() == 26;
    }
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<vector<int>>graph(26);
        for(int i = 1; i < N; i++) {
            const string& a = dict[i-1], b = dict[i];
            int j = 0;
            for(j; j<a.length() && j < b.length() && a[j]== b[j]; j++) {}
            if (j < a.length() && j < b.length()) 
                graph[a[j] - 'a'].push_back(b[j] - 'a');
            }
            string ans;
            top_sort(graph, ans);
            return ans;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends