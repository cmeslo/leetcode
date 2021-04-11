# 821. Shortest Distance to a Character

## 解釋：

Two pass.

## Code:

```cpp
vector<int> shortestToChar(string s, char c) {
    int n = s.size();
    vector<int> ans(n, n);
    int pos = -n;
    for (int i = 0; i < n; ++i) {
        if (s[i] == c) pos = i;
        ans[i] = i - pos;
    }
    for (int i = pos - 1; i >= 0; --i) {
        if (s[i] == c) pos = i;
        ans[i] = min(ans[i], pos - i);
    }
    return ans;
}
```

更簡潔的寫法：

```cpp
vector<int> shortestToChar(string s, char c) {
    int n = s.size();
    vector<int> dp(n);
    for (int i = 0; i < n; ++i)
        dp[i] = s[i] == c ? 0 : n;
    for (int i = 1; i < n; ++i)
        dp[i] = min(dp[i], dp[i - 1] + 1);
    for (int i = n - 2; i >= 0; --i)
        dp[i] = min(dp[i], dp[i + 1] + 1);
    return dp;
}
```
