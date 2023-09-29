#include <bits/stdc++.h>
using namespace std;

struct Node {
    bool isEOW;    
    vector<Node*>children;
    Node () : isEOW(false), children(26, NULL) {}
};
struct Trie {
    Node* root;
    Trie() : root(new Node()) {}
    void insert(string word) {
        Node* placer = root;
        for(char ch: word) {
          int index = ch - 'a';
          if (!placer->children[index])
            placer->children[index] = new Node();
          placer = placer->children[index];
        }
        placer->isEOW = true;
    }
    string search(string word) {
        Node* placer = root;
        string answer = "";
        for(char ch: word) {
          int index = ch - 'a';
          if (!placer->children[index] || !placer->children[index]->isEOW) break;
          answer.push_back(ch);
          placer = placer->children[index];
        }
        return answer;
    }

};
class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie* trie = new Trie();
        for(string word: words) {
            trie->insert(word);
        }
        string answer = "";
        for (string word: words) {
            string curr = trie->search(word);
            if (curr.size() > answer.size() || (curr.size() == answer.size() && answer > curr)) 
                answer = curr;
        }
        return answer;
    }
};