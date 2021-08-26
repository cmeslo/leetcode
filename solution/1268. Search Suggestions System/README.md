# 1268. Search Suggestions System

## Solution 1: Trie + DFS

```cpp
class TrieNode {
public:
    vector<TrieNode*> next;
    const string* word;
    TrieNode(): next(26), word(nullptr) {};
    // ~TrieNode() {}
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        TrieNode root;
        for (const string& w : products) {
            auto p = &root;
            for (const char& c : w) {
                if (!p->next[c - 'a'])
                    p->next[c - 'a'] = new TrieNode();
                p = p->next[c - 'a'];
            }
            p->word = &w;
        }
        
        vector<vector<string>> ans;
        auto p = &root;
        for (char& c : searchWord) {
            vector<string> cur;
            if (p) {
                p = p->next[c - 'a'];
                dfs(p, cur);
            }
            ans.push_back(cur);
        }
        return ans;
    }
    
private:
    void dfs(TrieNode* node, vector<string>& cur) {
        if (!node || cur.size() == 3) return;
        if (node->word) cur.push_back(*node->word);
        for (int i = 0; i < 26; ++i) {
            if (node->next[i])
                dfs(node->next[i], cur);
        }
    }
};
```
