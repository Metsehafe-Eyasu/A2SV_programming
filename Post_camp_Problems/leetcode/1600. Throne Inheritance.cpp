#include<bits/stdc++.h>
using namespace std;
class ThroneInheritance {
public:
    unordered_map<string, vector<string>>graph; 
    unordered_map<string, bool> dead;
    string root;
    ThroneInheritance(string kingName) {
        root = kingName;
    }
    
    void birth(string parentName, string childName) {
        graph[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead[name] = true;
    }

    void dfs(vector<string>& ans, string name) {
        if (!dead[name]) ans.push_back(name);
        for(auto& a: graph[name])
            dfs(ans, a);
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> answer;
        dfs(answer, root);
        return answer;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */