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
