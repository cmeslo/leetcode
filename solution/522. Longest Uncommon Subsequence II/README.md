# 522. Longest Uncommon Subsequence II

## Solution: Brute force

```cpp
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
