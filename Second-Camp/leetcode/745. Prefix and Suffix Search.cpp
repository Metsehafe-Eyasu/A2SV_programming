#include <bits/stdc++.h>
using namespace std;

struct Node {
    int index;    
    Node* children[27];
    Node () : index(-1) {
        memset(children, NULL, sizeof(children));
    }
};
struct Trie {
    Node* root;
    Trie() : root(new Node()) {}
    void insert(string& word, int index) {
        Node* placer = root;
        for(char ch: word) {
          int ch_index = ch - 'a';
          if (!placer->children[ch_index])
            placer->children[ch_index] = new Node();
          placer = placer->children[ch_index];
          placer->index = index;
        }
    }
    int search(string& word) {
        Node* placer = root;
        for(char& ch: word) {
          int ch_index = ch - 'a';
          if (!placer->children[ch_index]) return -1;
          placer = placer->children[ch_index];
        }
        return placer->index;
    }
};
class WordFilter {
public:
    Trie* trie;
    WordFilter(vector<string>& words) : trie(new Trie()) {
        for (int k = 0; k < words.size(); k++) {
            string word = words[k], temp = word;
            for(int i = 0; i < word.size(); i++) {
                string comb = temp+"{"+word;
                trie->insert(comb, k);
                temp.erase(temp.begin());
            }
        }
    }
    
    int f(string pref, string suff) {
        string search = suff+"{"+pref;
        return trie->search(search);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */