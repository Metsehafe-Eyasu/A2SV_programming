#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    bool isWord;
    Node* children[26];        
    Node () {
        isWord = false;
        memset(children, NULL, sizeof(children));
    }
};

class WordDictionary {
    Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* placer = root;
        for (char c: word) {
            int index = c - 'a';
            if (!placer->children[index]) placer->children[index] = new Node();
            placer = placer->children[index];
        }
        placer->isWord = true;
    }
    
    bool search(string word) {
        return helper(root, word, 0);
    }
    bool helper(Node* node, string& word, int index) {
        if (index == word.length())
            return node->isWord;
        char c = word[index];
        if (c == '.') {
            for (int i = 0; i < 26; i++)
                if ( node->children[i] != NULL && helper(node->children[i], word, index+1) ) return true;
            
            return false;
        }
        if ( node->children[c - 'a'] == NULL) 
            return false;
        return helper(node->children[c - 'a'], word, index+1);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */