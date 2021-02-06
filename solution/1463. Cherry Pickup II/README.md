# 1463. Cherry Pickup II

## Top-down (1463_01.cpp)

```cpp
int cherryPickup(vector<vector<int>>& grid) {
    int h = grid.size(), w = grid[0].size();

    vector<vector<vector<int>>> cache(h, vector<vector<int>>(w, vector<int>(w, -1)));

    function<int(int, int, int)> dp = [&](int y, int x1, int x2) {
        if (y < 0 || y >= h || x1 < 0 || x1 >= w || x2 < 0 || x2 >= w) return 0;
        int& ans = cache[y][x1][x2];
        if (ans != -1) return ans;

        const int cur = grid[y][x1] + (x1 != x2) * grid[y][x2];
        for (int d1 = -1; d1 <= 1; ++d1)
            for (int d2 = -1; d2 <= 1; ++d2)
                ans = max(ans, cur + dp(y + 1, x1 + d1, x2 + d2));

        return ans;
    };

    return dp(0, 0, w - 1);
}
```

- Time complexity: O(h * w^2 * 9)
- Space complexity: O(h * w^2)


## Bottom-up DP (1463_02.cpp)

從下向上走，有明確的目標格子（左上和右上），可以省掉最後用 O(n^2) 查找最終結果。

### 三維DP

```cpp
int cherryPickup(vector<vector<int>>& grid) {
    int h = grid.size(), w = grid[0].size();
    vector<vector<vector<int>>> dp(h + 2, vector<vector<int>>(w + 2, vector<int>(w + 2)));

    for (int y = h; y >= 1; --y) {
        for (int x1 = 1; x1 <= w; ++x1) {
            for (int x2 = 1; x2 <= w; ++x2) {
                int cur = grid[y - 1][x1 - 1] + (x1 != x2) * grid[y - 1][x2 - 1];
                int& ans = dp[y][x1][x2];
                for (int d1 = -1; d1 <= 1; ++d1)
                    for (int d2 = -1; d2 <= 1; ++d2)
                        ans = max(ans, cur + dp[y + 1][x1 + d1][x2 + d2]);
            }
        }
    }

    return dp[1][1][w];
}
```

### 空間壓縮成二維

```cpp
int cherryPickup(vector<vector<int>>& grid) {
    int h = grid.size(), w = grid[0].size();
    vector<vector<int>> dp(w + 2, vector<int>(w + 2));

    for (int y = h; y >= 1; --y) {
        vector<vector<int>> tmp(w + 2, vector<int>(w + 2));
        for (int x1 = 1; x1 <= w; ++x1) {
            for (int x2 = 1; x2 <= w; ++x2) {
                int cur = grid[y - 1][x1 - 1] + (x1 != x2) * grid[y - 1][x2 - 1];
                int& ans = tmp[x1][x2];
                for (int d1 = -1; d1 <= 1; ++d1)
                    for (int d2 = -1; d2 <= 1; ++d2)
                        ans = max(ans, cur + dp[x1 + d1][x2 + d2]);
            }
        }
        dp.swap(tmp);
    }

    return dp[1][w];
}
```

#### 從上向下走的代碼：

```cpp
int cherryPickup(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();

    vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
    dp[0][n - 1] = grid[0][0] + grid[0][n - 1];

    for (int r = 1; r < m; ++r) {
        auto old_dp = dp;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int a = i - 1; a <= i + 1; ++a) {
                    for (int b = j - 1; b <= j + 1; ++b) {
                        if  (a < 0 || a >= n || b < 0 || b >= n) continue;
                        dp[i][j] = max(dp[i][j], old_dp[a][b] + grid[r][i] + (i == j ? 0 : grid[r][j]));
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}
```

- Time complexity: O(h * w^2 * 9)
- Space complexity: O(w^2)
