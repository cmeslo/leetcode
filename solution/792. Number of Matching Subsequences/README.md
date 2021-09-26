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
