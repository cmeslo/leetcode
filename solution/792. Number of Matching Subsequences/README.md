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

or

```cpp
// Runtime: 245 ms, Your runtime beats 82.26 % of cpp submissions.
// Memory Usage: 48 MB, Your memory usage beats 83.92 % of cpp submissions.

int numMatchingSubseq(string s, vector<string>& words) {
    vector<vector<int>> pos(26);
    for (int i = 0; i < s.size(); ++i) {
        pos[s[i] - 'a'].push_back(i);
    }

    int res = 0;
    for (string& w : words) {
        bool ok = true;
        int i = 0;
        for (char& c : w) {
            int x = c - 'a';
            auto it = lower_bound(pos[x].begin(), pos[x].end(), i);
            if (it == pos[x].end()) {
                ok = false;
                break;
            }
            i = (*it) + 1;
        }
        if (ok) ++res;
    }
    return res;
}
```

## Solution 3: 狀態機

### 解釋

Solution 2 要用 binary search - ```O(logN)``` 的方法查找下一個字母的出現位置

這裡可以先做一點預處理，使用 ```O(1)``` 的方法查找下一個字母的出現位置

```
0 1 2 3 4 5 6
  a b c a d e

next[0][a] = 1 <--從位置 0，看下一個字母 'a' 的出現位置
next[0][b] = 2
...
next[1][a] = 4
```

### Code
```cpp
// Your runtime beats 68.91 % of cpp submissions.
// Your memory usage beats 91.55 % of cpp submissions.

int numMatchingSubseq(string s, vector<string>& words) {
    int n = s.size();

    int next[n + 1][26];

    for (int i = 0; i < 26; ++i)
        next[n][i] = -1;

    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < 26; ++j)
            next[i][j] = next[i + 1][j];
        next[i][s[i] - 'a'] = i + 1;
    }

    int ans = 0;
    for (string& w : words) {
        int i = 0;
        bool flag = true;
        for (char& c : w) {
            i = next[i][c - 'a'];
            if (i == -1) {
                flag = false;
                break;
            }
        }
        if (flag) ++ans;
    }

    return ans;
}
```
