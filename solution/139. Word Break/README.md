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

## 139_02.cpp

```cpp
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string_view> dict(wordDict.begin(), wordDict.end());
        unordered_map<string_view, bool> memo;
        return dfs(s, 0, dict, memo);
    }
    
private:
    bool dfs(const string_view& s, int len, unordered_set<string_view>& dict, unordered_map<string_view, bool>& memo) {
        if (dict.find(s) != dict.end()) return memo[s] = true;
        if (memo.find(s) != memo.end()) return memo[s];
        
        for (int i = len + 1; i < s.length(); ++i) {
            const string_view& left = s.substr(0, i);
            const string_view& right = s.substr(i);
            if (dict.count(right) && dfs(left, 0, dict, memo))
                return memo[s] = true;
        }
        
        return memo[s] = false;
    }
};
```

or

```cpp
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string_view> dict(wordDict.begin(), wordDict.end());
        unordered_map<string_view, bool> memo;
        return dfs(s, 0, dict, memo);
    }
    
private:
    bool dfs(const string_view& s, int len, unordered_set<string_view>& dict, unordered_map<string_view, bool>& memo) {
        if (dict.find(s) != dict.end()) return memo[s] = true;
        if (memo.find(s) != memo.end()) return memo[s];
        
        for (int i = len + 1; i < s.length(); ++i) {
            const string_view& left = s.substr(0, i);
            const string_view& right = s.substr(i);
            if (dict.count(left) && dfs(right, 0, dict, memo)) // check the left part in a dict, dfs the right part
                return memo[s] = true;
        }
        
        return memo[s] = false;
    }
};
```
