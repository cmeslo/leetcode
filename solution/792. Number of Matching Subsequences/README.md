# 792. Number of Matching Subsequences

## Solution 1: Brute force (two pointers) + memo

```cpp
// Your runtime beats 74.49 % of cpp submissions.
// Your memory usage beats 91.51 % of cpp submissions.

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans = 0;
        for (const string& w : words)
            ans += isMatch(s, w);
        return ans;
    }
    
private:
    unordered_map<string, bool> memo_;
    
    bool isMatch(const string& s, const string& w) {
        if (memo_.count(w)) return memo_[w];
        int i = 0, j = 0;
        while (i < s.size()) {
            if (s[i] == w[j]) ++j;
            if (j == w.size()) return memo_[w] = true;
            ++i;
        }
        return memo_[w] = false;
    }
};
```

## Solution 2: Indexing + binary search

```cpp
// Your runtime beats 70.85 % of cpp submissions.
// Your memory usage beats 52.87 % of cpp submissions.

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> pos(128);
        for (int i = 0; i < s.size(); ++i)
            pos[s[i]].push_back(i);
        
        int ans = 0;
        for (const string& word : words)
            if (isMatch(pos, word))
                ++ans;
        
        return ans;
    }
    
private:
    bool isMatch(vector<vector<int>>& pos, const string& word) {
        int i = 0;
        for (const char& c : word) {
            auto it = std::lower_bound(pos[c].begin(), pos[c].end(), i);
            if (it == pos[c].end()) return false;
            i = *it + 1;
        }
        return true;
    }
};
```
