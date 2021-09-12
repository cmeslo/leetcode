# 1690. Stone Game VII

## Solution 1: Recursion + memo

```cpp
class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        int sum = accumulate(begin(stones), end(stones), 0);
        dp.clear();
        dp.resize(n, vector<int>(n));
        return dfs(stones, 0, n - 1, sum);
    }
    
private:
    vector<vector<int>> dp;
    
    int dfs(vector<int>& stones, int l, int r, int sum) {
        if (l == r) return 0;
        if (dp[l][r]) return dp[l][r];
        
        int takeLeft = dfs(stones, l + 1, r, sum - stones[l]);
        int takeRight = dfs(stones, l, r - 1, sum - stones[r]);
        
        return dp[l][r] = max(sum - stones[l] - takeLeft,
                              sum - stones[r] - takeRight);
    }
};
```

## Solution 2: DP

### 解釋

```
dp[i][j] = max(sum[i+1:j] - dp[i+1][j],
               sum[i:j-1] - dp[i][j-1])

x [x x x x x x]
i            j

[x x x x x x] x
i             j
```

### Code
```cpp
class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<int> presum(n + 1);
        for (int i = 1; i <= n; ++i)
            presum[i] = presum[i - 1] + stones[i - 1];
        
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        // 另一種 for loop 的方法
        // for (int len = 2; len <= n; ++len) {
        //     for (int i = 1; i + len - 1 <= n; ++i) {
        //         int j = i + len - 1;
        //         dp[i][j] = max(presum[j] - presum[i] - dp[i+1][j],
        //                        presum[j-1] - presum[i-1] - dp[i][j-1]);
        //     }
        // }
        for (int i = n; i >= 1; --i) {
            for (int j = i + 1; j <= n; ++j) {
                dp[i][j] = max(presum[j] - presum[i] - dp[i+1][j],
                               presum[j-1] - presum[i-1] - dp[i][j-1]);
            }
        }
        return dp[1][n];
    }
};
```
