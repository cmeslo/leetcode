# 639. Decode Ways II

## Solution: DP

### 分析過程
```
x x x x x x x 2
dp[i] = dp[i-1]

x x x x x x 2 6
dp[i] += dp[i-2]

x x x x x x * 6
dp[i] += dp[i-2] * 2

x x x x x x * 7
dp[i] += dp[i-2] * 1

x x x x x x x *
dp[i] = dp[i-1] * 9

x x x x x x 1 *
dp[i] += dp[i-2] * 9 {* = 1-9}

x x x x x x 2 *
dp[i] += dp[i-2] * 6 {* = 1,2,3,4,5,6}

x x x x x x * *
dp[i] = dp[i-2] * 15

11,12,...,19 = 9
21,22,...,26 = 6
9 + 6 = 15
```

### Code

```cpp
int numDecodings(string s) {
    const int M = 1e9 + 7;
    int n = s.size();
    s.insert(s.begin(), '#');

    vector<long> dp(n + 1);
    dp[0] = 1;
    if (s[1] == '*')
        dp[1] = 9;
    else
        dp[1] = s[1] == '0' ? 0 : 1;

    for (int i = 2; i <= n; ++i) {
        if (s[i] == '*') {
            dp[i] = dp[i-1] * 9;
            if (s[i - 1] == '1')
                dp[i] += dp[i-2] * 9;
            else if (s[i - 1] == '2')
                dp[i] += dp[i-2] * 6;
            else if (s[i - 1] == '*')
                dp[i] += dp[i-2] * 15;
        } else {
            if (s[i] != '0')
                dp[i] = dp[i-1];
            if (s[i-1] == '*')
                dp[i] += dp[i-2] * (s[i] <= '6' ? 2 : 1);
            else if ((s[i-1] == '1' && s[i] <= '9') || (s[i-1] == '2' && s[i] <= '6'))
                dp[i] += dp[i-2];
        }
        dp[i] %= M;
    }
    return dp[n];
}
```
