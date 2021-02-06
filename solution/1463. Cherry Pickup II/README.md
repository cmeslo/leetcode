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

### 解釋

由於走格子要考慮各種路徑、移動方法，所以很容易可以聯想到DP，關鍵是狀態轉移方程要怎麼寫：

#### 當從上向下走時：

```
dp[y][x1][x2] = dp[y - 1][a][b] + grid[x1] + grid[x2]
```
x1 代表 機械人1 在當前行的位置，
x2 代表 機械人2 在當前行的位置。

a 和 b 分別代表機械人上一輪的可能位置，機械人1由 a 走到 x1，機械人2由 b 走到 x2，

a 有三種取值：(x1 - 1), x1, (x1 + 1)

b 有三種取值：(x2 - 1), x2, (x2 + 1)

a 和 b 各有三種可能性，合共 9 種組合。

如果 x1 和 x2 在同一格子上，只有一個人可以拿到cherry，所以有：
```
dp[y][x1][x2] = dp[y - 1][a][b] + grid[x1] + (x1 != x2) * grid[x2]
```

#### 另外有兩個技巧：

1. 擴充邊界，可以忽略邊界處理代碼，讓代碼更簡潔。
2. 從下向上走，有明確的目標格子（左上和右上），可以省掉最後用 O(n^2) 查找最終結果。

```
dp[y][x1][x2] = dp[y + 1][a][b] + grid[x1] + (x1 != x2) * grid[x2]
```

### 代碼 - 三維DP

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

### 代碼 - 空間壓縮成二維

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

### 代碼 - 不擴充邊界，然後從上向下走：

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
