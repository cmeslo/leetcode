# 647. Palindromic Substrings

## Solution 1 - DP

```cpp
int countSubstrings(string s) {
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n));

    int ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i; j < n; ++j) {
            if (j - i + 1 < 3)
                dp[i][j] = s[i] == s[j];
            else
                dp[i][j] = s[i] == s[j] ? dp[i + 1][j - 1] : false;
            ans += dp[i][j];
        }
    }

    return ans;
}
```

## Solution 2 - Brute force

```cpp
// Your runtime beats 91.73 % of cpp submissions.
// Your memory usage beats 82.80 % of cpp submissions.

class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            ans += extendPalindromic(s, i, i);
            ans += extendPalindromic(s, i, i + 1);
        }
        return ans;
    }

private:
    int extendPalindromic(const string& s, int l, int r) {
        int cnt = 0;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            ++cnt;
            --l, ++r;
        }
        return cnt;
    }
};
```
