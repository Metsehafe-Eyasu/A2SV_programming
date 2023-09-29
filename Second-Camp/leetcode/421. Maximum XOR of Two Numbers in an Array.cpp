#include <bits/stdc++.h>
using namespace std;

struct Node {
  vector<Node*>children;
  Node () : children(2, NULL) {}
};

struct Trie {
  Node* root;
  Trie() : root(new Node()) {}
  void insert(int num) {
    Node* placer = root;
    int i = 31;
    while(i >= 0) {
      int val = (num >> i) & 1;
      if (!placer->children[val]) 
        placer->children[val] = new Node();
      placer = placer->children[val];
      i--;
    }
  }
  int calc(int num) {
    int ans = 0;
    Node* finder = root;
    int i = 31;
    while(i >= 0) {
      int val = (num >> i) & 1;
      if (finder->children[(val^1)]) {
        ans += (1 << i);
        finder = finder->children[(val^1)];
      }
      else if (finder->children[val])
        finder = finder->children[val];
      else break;
      i--;
    }
    return ans;
  }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int max_ = 0;
        Trie* trie = new Trie();
        for(int curr: nums) {
            max_ = max(max_, trie->calc(curr));
            trie->insert(curr);
        }
        return max_;
    }
};