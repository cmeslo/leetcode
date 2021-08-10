# 1048. Longest String Chain

## Solution 1: DP

類似 longest increasing subsequence 問題

```cpp
// Your runtime beats 76.19 % of cpp submissions.
// Your memory usage beats 94.20 % of cpp submissions.

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(begin(words), end(words), [&](string &a, string& b) {
            return a.size() < b.size();
        });
        
        int n = words.size();
        vector<int> dp(n, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (isPredecessor(words[j], words[i]))
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        return *max_element(begin(dp), end(dp));
    }
    
private:
    bool isPredecessor(const string& A, const string& B) {
        if (A.size() + 1 != B.size()) return false;
        
        int a = 0, b = 0;
        int diff = 0;
        while (a < A.size()) {
            if (A[a] != B[b]) {
                if (++diff > 1) break;
                ++b;
            } else {
                ++a, ++b;
            }
        }
        return diff <= 1;
    }
};
```

加一點優化：

```cpp
// Your runtime beats 90.74 % of cpp submissions.
// Your memory usage beats 89.86 % of cpp submissions.

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(begin(words), end(words), [&](string &a, string& b) {
            return a.size() < b.size();
        });
        
        int n = words.size();
        vector<int> dp(n, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) { // 從前往向走
                if (words[j].size() == words[i].size()) continue; // 相同 size 的跳過
                if (words[j].size() + 1 < words[i].size()) break; // 只處理 size 剛好小 1 的
                if (isPredecessor(words[j], words[i]))
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        return *max_element(begin(dp), end(dp));
    }
    
private:
    bool isPredecessor(const string& A, const string& B) {
        if (A.size() + 1 != B.size()) return false;
        
        int a = 0, b = 0;
        int diff = 0;
        while (a < A.size()) {
            if (A[a] != B[b]) {
                if (++diff > 1) break;
                ++b;
            } else {
                ++a, ++b;
            }
        }
        return diff <= 1;
    }
};
```
