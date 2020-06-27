# 279. Perfect Squares

## DP

看到題目，因為要求最少組成數目，所以很自然就想到用DP做

|   | 1         | 4         | 9 |
|---|-----------|-----------|---|
| 1 | 1+dp[1-1] | X         | X |
| 2 | 1+dp[2-1] | X         | X |
| 3 | 1+dp[3-1] | X         | X |
| 4 | 1+dp[4-1] | 1         | X |
| 5 | 1+dp[5-1] | 1+dp[5-4] | X |
| 6 | 1+dp[6-1] | 1+dp[6-4] | X |

### 最開始寫的：
```cpp
int numSquares(int n) {
    vector<int> nums;
    for (int i = 1; i <= n; i++) {
        if (i*i <= n)
            nums.emplace_back(i*i);
        else
            break;
    }

    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int num : nums) {
            if (num > i) break;
            if (num == i) {
                dp[i] = 1; break;
            }
            dp[i] = min(dp[i], 1 + dp[i-num]);
        }
    }
    return dp[n];
}
```

### 優化後：
```cpp
int numSquares(int n) {
    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j*j <= i; j++) {
            dp[i] = min(dp[i], 1 + dp[i-j*j]);
        }
    }
    return dp[n];
}
```

但其實還有數學方法去解這題，時間複雜度更低。
