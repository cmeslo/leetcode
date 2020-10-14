# 139. Word Break

## 139_01.cpp

Trie + DP

```cpp
class TrieNode {
public:
    vector<TrieNode*> next;
    bool isWord;
    TrieNode(): next(26), isWord(false) {};
    ~TrieNode() {
        for (auto* n : next)
            delete n;
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        auto* root = buildTrie(wordDict);
        
        int n = s.length();
        vector<bool> dp(n + 1, 0);
        dp[0] = true;
        for (int i = 0; i < n; ++i) {
            if (!dp[i]) continue;
            auto* p = root;
            int j = i;
            while (j < n && p->next[s[j] - 'a']) {
                p = p->next[s[j++] - 'a'];
                if (p->isWord) dp[j] = true;
            }
            if (dp[n]) return true;
        }
        
        return dp[n];
    }
    
    TrieNode* buildTrie(vector<string>& wordDict) {
        TrieNode* root = new TrieNode();
        for (const string& word : wordDict) {
            auto* p = root;
            for (const char& c : word) {
                auto& next = p->next[c - 'a'];
                if (!next) next = new TrieNode();
                p = next;
            }
            p->isWord = true;
        }
        return root;
    }
};
```
