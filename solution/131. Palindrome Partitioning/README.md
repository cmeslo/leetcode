# 131. Palindrome Partitioning

## 寫法一：DFS + 用雙指針判斷 Palindrome

```cpp
class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<string> cur;
        vector<vector<string>> ans;
        dfs(s, 0, cur, ans);
        return ans;
    }
    
private:
    void dfs(const string& s, int start, vector<string>& cur, vector<vector<string>>& ans) {
        if (start == s.length()) {
            ans.push_back(cur);
            return;
        }
        
        for (int i = start; i < s.length(); ++i) {
            if (isPalindrome(s, start, i)) {
                cur.push_back(s.substr(start, i - start + 1));
                dfs(s, i + 1, cur, ans);
                cur.pop_back();
            }
        }
    }
    
    bool isPalindrome(const string& s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }
};
```

or

## 寫法二：DFS + 用 DP 判斷 Palindrome

```cpp
class Solution {
public:
    vector<vector<string>> partition(string s) {
        n = s.size();
        dp.resize(n, vector<int>(n, 1));
        for (int l = 2; l <= n; ++l) {
            for (int i = 0; i < n && i + l - 1 < n; ++i) {
                int j = i + l - 1;
                dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);
            }
        }
        dfs(s, 0);
        return res;
    }
    
private:
    vector<vector<int>> dp;
    vector<vector<string>> res;
    vector<string> cur;
    int n;
    
    void dfs(string& s, int i) {
        if (i == n) {
            res.push_back(cur);
            return;
        }
        for (int j = i; j < n; ++j) {
            if (dp[i][j]) {
                cur.push_back(s.substr(i, j - i + 1));
                dfs(s, j + 1);
                cur.pop_back();
            }
        }
    }
};


// [x x x x] x x x
//  i     j
 
//  dp[i][j] && dfs(j + 1)
```
