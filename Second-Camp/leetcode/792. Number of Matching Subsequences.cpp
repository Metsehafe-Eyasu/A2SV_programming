#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int isWord;
    Node* children[26];        
    Node () : isWord(0) {
        memset(children, NULL, sizeof(children));
    }
};

class Trie {
public:
    Node* root;
    Trie() : root(new Node()) {}
    void insert(string word) {
        Node* placer = root;
        for (char c: word) {
            int index = c - 'a';
            if (!placer->children[index]) placer->children[index] = new Node();
            placer = placer->children[index];
        }
        placer->isWord++;
    }
    int search(int index, Node* curr, vector<int>dict[]) {
        int count = 0;
        for(int i = 0; i < 26; i++) {
            if (curr->children[i]) {
                int newIdx = upper_bound(dict[i].begin(), dict[i].end(), index) - dict[i].begin();
                if (newIdx == dict[i].size()) continue;
                count += search(dict[i][newIdx], curr->children[i], dict);
            }
        }
        return count + curr->isWord;
    }
};
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        Trie* trie = new Trie();
        for(string word: words) trie->insert(word);
        vector<int>dict[26];
        for(int i = 0; i < s.length(); i++) {
            dict[s[i] - 'a'].push_back(i);
        }
        return trie->search(-1, trie->root, dict);
    }
};