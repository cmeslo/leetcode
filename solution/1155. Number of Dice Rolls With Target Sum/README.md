# 1155. Number of Dice Rolls With Target Sum

## Solution 1: DP

```cpp
// Runtime: 223 ms, Memory Usage: 10.5 MB

int numRollsToTarget(int n, int k, int target) {
    const int M = 1e9 + 7;
    vector<vector<long>> dp(n + 1, vector<long>(target + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int x = 1; x <= target; ++x) {
            for (int j = 1; j <= k && x >= j; ++j) {
                dp[i][x] = (dp[i][x] + dp[i - 1][x - j]) % M;
            }
        }
    }
    return dp[n][target];
}
```

## Solution 2: DFS

```cpp
// Runtime: 59 ms, Memory Usage: 17.8 MB

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        memo.resize(31, vector<int>(1001, -1));
        return dp(n, k, target);
    }
    
    const int M = 1e9 + 7;
    vector<vector<int>> memo;
    int dp(int n, int k, int target) {
        if (n <= 0 || target <= 0) return n == 0 && target == 0;
        if (memo[n][target] != -1) return memo[n][target];
        int res = 0;
        for (int j = 1; j <= k; ++j) {
            res = (res + dp(n - 1, k, target - j)) % M;
        }
        return memo[n][target] = res;
    }
};
```
