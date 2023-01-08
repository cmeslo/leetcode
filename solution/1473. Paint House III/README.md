# 1473. Paint House III

## Solution: DP

```cpp
int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
    vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(target + 1, vector<int>(n + 1, INT_MAX)));

    houses.insert(houses.begin(), 0);

    for (int k = 0; k <= n; ++k)
        dp[0][0][k] = 0;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= target; ++j) {
            if (houses[i] == 0) {
                for (int k = 1; k <= n; ++k) {
                    if (dp[i - 1][j][k] != INT_MAX) {
                        dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k] + cost[i - 1][k - 1]);
                    }

                    for (int pre = 1; pre <= n; ++pre) {
                        if (k == pre || dp[i - 1][j - 1][pre] == INT_MAX) continue;
                        dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - 1][pre] + cost[i - 1][k - 1]);
                    }
                }
            } else {
                int k = houses[i];
                if (dp[i - 1][j][k] != INT_MAX)
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k]);

                for (int pre = 1; pre <= n; ++pre) {
                    if (k == pre || dp[i - 1][j - 1][pre] == INT_MAX) continue;
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - 1][pre]);
                }
            }
        }
    }

    int res = INT_MAX;
    for (int x : dp[m][target])
        if (x != -1)
            res = min(res, x);
    return res == INT_MAX ? -1 : res;
}
```
