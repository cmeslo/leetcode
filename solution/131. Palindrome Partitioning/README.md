# 131. Palindrome Partitioning

## 寫法一：DFS + 用雙指針判斷 Palindrome

```cpp
class Solution {
public:
    vector<vector<string>> partition(string s) {
        n = s.size();
        dfs(s, 0);
        return res;
    }
    
private:
    int n;
    vector<vector<string>> res;
    vector<string> cur;
    
    void dfs(const string& s, int i) {
        if (i == n) {
            res.push_back(cur);
            return;
        }
        for (int j = i; j < n; ++j) {
            if (isPalindrome(s, i, j)) {
                cur.push_back(s.substr(i, j - i + 1));
                dfs(s, j + 1);
                cur.pop_back();
            }
        }
    }
    
    bool isPalindrome(const string& s, int i, int j) {
        while (i < j) {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }
};


// a  a a   a b a
// x (x x) [x x x]
//    i j
   
// s[i:j] is palindrome + dfs(j + 1)
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
