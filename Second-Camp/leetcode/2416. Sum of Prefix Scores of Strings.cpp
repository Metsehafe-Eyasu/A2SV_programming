#include <bits/stdc++.h>
using namespace std;

struct Node {
    int count;    
    Node* children[26];
    Node () : count(0) {
        memset(children, NULL, sizeof(children));
    }
};
struct Trie {
    Node* root;
    Trie() : root(new Node()) {}
    void insert(string& word) {
        Node* placer = root;
        for(char ch: word) {
          int index = ch - 'a';
          if (!placer->children[index])
            placer->children[index] = new Node();
          placer->children[index]->count++;
          placer = placer->children[index];
        }
    }
    int search(string& word) {
        Node* placer = root;
        int ans = 0;
        for(char ch: word) {
          int index = ch - 'a';
          ans += placer->children[index]->count;
          placer = placer->children[index];
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie* trie = new Trie();
        for(string& word: words) trie->insert(word);
        vector<int>arr;
        for(string& word: words) arr.push_back(trie->search(word));
        return arr;
    }
};