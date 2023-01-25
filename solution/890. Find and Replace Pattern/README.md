# 890. Find and Replace Pattern

## Solution 1: map

```cpp
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int n = pattern.size();
        vector<string> ans;
        vector<int> m1(26), m2(26);
        
        for (string& w : words) {
            if (w.size() != n) continue;
            fill(m1.begin(), m1.end(), -1);
            fill(m2.begin(), m2.end(), -1);
            int i;
            for (i = 0; i < n; ++i) {
                int a = w[i] - 'a';
                int b = pattern[i] - 'a';
                if (m1[a] == -1 && m2[b] == -1) {
                    m1[a] = b;
                    m2[b] = a;
                } else if (m1[a] != b || m2[b] != a)
                    break;
            }
            if (i == n) ans.push_back(w);
        }
        
        return ans;
    }
```

## Solution 2: Normalize

```cpp
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        string p = normalize(pattern);
        for (string& w : words)
            if (normalize(w) == p)
                ans.push_back(w);
        return ans;
    }
    
private:
    string normalize(string s) {
        unordered_map<char, int> m;
        for (char& c : s)
            if (m.find(c) == m.end())
                m[c] = m.size();
        for (int i = 0; i < s.size(); ++i)
            s[i] = 'a' + m[s[i]];
        return s;
    }
};
```
