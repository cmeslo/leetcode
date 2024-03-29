# 1473. Paint House III

## Solution: DP

### 寫法一: O(n^4)

```cpp
int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
    int dp[101][101][21];
    // vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(target + 1, vector<int>(n + 1, INT_MAX / 2)));
    for (int i = 0; i <= m; ++i)
        for (int j = 0; j <= target; ++j)
            for (int k = 0; k <= n; ++k)
                dp[i][j][k] = INT_MAX / 2;

    houses.insert(houses.begin(), 0);
    cost.insert(cost.begin(), {0});

    for (int k = 0; k <= n; ++k)
        dp[0][0][k] = 0;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= target; ++j) {
            if (houses[i] == 0) {
                for (int k = 1; k <= n; ++k) {
                    for (int kk = 1; kk <= n; ++kk) {
                        if (k == kk)
                            dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k] + cost[i][k - 1]);
                        else
                            dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - 1][kk] + cost[i][k - 1]);
                    }
                }
            } else {
                int k = houses[i];
                for (int kk = 1; kk <= n; ++kk) {
                    if (k == kk)
                        dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k]);
                    else
                        dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - 1][kk]);
                }
            }
        }
    }

    int res = INT_MAX / 2;
    for (int k = 1; k <= n; ++k)
        res = min(res, dp[m][target][k]);
    return res == INT_MAX / 2 ? -1 : res;
}
```

### 寫法二: O(n^3)

```cpp
int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
    int dp[101][101][21];
    for (int i = 0; i <= m; ++i)
        for (int j = 0; j <= target; ++j)
            for (int k = 0; k <= n; ++k)
                dp[i][j][k] = INT_MAX / 2;

    houses.insert(houses.begin(), 0);
    cost.insert(cost.begin(), {0});

    for (int k = 0; k <= n; ++k)
        dp[0][0][k] = 0;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= target; ++j) {
            if (houses[i] == 0) {
                vector<pair<int, int>> pre; // {cost, color}
                for (int kk = 1; kk <= n; ++kk) {
                    pre.push_back({dp[i - 1][j - 1][kk], kk});
                }
                sort(pre.begin(), pre.end());

                for (int k = 1; k <= n; ++k) {
                    // consider i-1 and i houses painted same color
                    dp[i][j][k] = dp[i - 1][j][k] + cost[i][k - 1];

                    // consider i-1 and i houses painted different color
                    if (k != pre[0].second)
                        dp[i][j][k] = min(dp[i][j][k], pre[0].first + cost[i][k - 1]);
                    else
                        dp[i][j][k] = min(dp[i][j][k], pre[1].first + cost[i][k - 1]);
                }
                // for (int k = 1; k <= n; ++k) {
                //     for (int kk = 1; kk <= n; ++kk) {
                //         if (k == kk)
                //             dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k] + cost[i][k - 1]);
                //         else
                //             dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - 1][kk] + cost[i][k - 1]);
                //     }
                // }
            } else {
                int k = houses[i];
                for (int kk = 1; kk <= n; ++kk) {
                    if (k == kk)
                        dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][kk]);
                    else
                        dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - 1][kk]);
                }
            }
        }
    }

    int res = INT_MAX / 2;
    for (int k = 1; k <= n; ++k)
        res = min(res, dp[m][target][k]);
    return res == INT_MAX / 2 ? -1 : res;
}
```
