# 522. Longest Uncommon Subsequence II

## Solution 1: Brute force

```cpp
// Runtime: 632 ms
// Memory Usage: 63.5 MB

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        const int n = strs.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            auto subs = getSubsequence(strs[i]);
            sort(subs.begin(), subs.end(), [&](string& a, string& b) { return a.size() > b.size(); });
            
            for (const string& sub : subs) {
                int j;
                for (j = 0; j < n; ++j) {
                    if (sub.size() > strs[j].size()) continue;
                    if (i == j) continue;
                    if (isSubsequence(sub, strs[j])) break;
                }
                if (j == n) ans = max(ans, (int)sub.size());
            }
            cout << endl;
        }
        return ans == 0 ? -1 : ans;
    }
    
private:
    vector<string> getSubsequence(const string& str) {
        unordered_set<string> subs;
        int n = str.size();
        int size = (1 << n);
        for (int s = 0; s < size; ++s) {
            string cur;
            for (int i = n - 1; i >= 0; --i) {
                if (s & (1 << i))
                    cur.push_back(str[n - i - 1]);
            }
            subs.insert(cur);
        }
        vector<string> ans;
        for (string sub : subs)
            ans.push_back(sub);
        return ans;
    }
    
    bool isSubsequence(const string& sub, const string& str) {
        int i = 0;
        for (int j = 0; j < str.size(); ++j) {
            if (sub[i] == str[j]) ++i;
            if (i == sub.size()) return true;
        }
        return false;
    }
};
```

## Solution 2

觀察隱藏規則：「如果 s 的 subsequence 是特殊序列 那麼 s 也是特殊序列 因此只需看整體 s 就可以了」

因為 s 的子序列如果是 uncommon 的，再添加幾個字符變成完整的 s，也會是 uncommon 的，所以只要判斷 s 就可以了，不用生成它的所有子序列，逐個判斷。

```cpp
// Runtime: 0 ms, Your runtime beats 100.00 % of cpp submissions.
// Memory Usage: 8.3 MB, Your memory usage beats 69.27 % of cpp submissions.

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int n = strs.size();
        sort(strs.begin(), strs.end(), [&](const string& a, const string& b) {
            return a.size() > b.size();
        });
        
        for (int i = 0; i < n; ++i) {
            bool is_uncommon = true;
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                if (isSubsequence(strs[i], strs[j])) {
                    is_uncommon = false;
                    break;
                }
            }
            if (is_uncommon) return strs[i].size();
        }
        return -1;
    }
    
private:
    bool isSubsequence(const string& a, const string& b) {
        if (a.size() > b.size()) return false;
        int i = 0;
        for (int j = 0; i < a.size() && j < b.size(); ++j)
            if (a[i] == b[j]) ++i;
        return i == a.size();
    }
};
```
