# 877. Stone Game

## Solution 1: Top down

```
x x x [i x x x j] x x

dp[i][j] = max(presum[j] - presum[i-1] - solve(i+1, j)
               presum[j] - presum[i-1] - solve(i, j-1))
```

```cpp
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        piles.insert(piles.begin(), 0);
        
        for (int i = 1; i <= n; ++i)
            presum[i] = presum[i - 1] + piles[i];
        
        int gain = solve(piles, 1, n);
        return gain > presum[n] - gain;
    }
    
private:
    int presum[501];
    int memo[501][501];
    
    int solve(vector<int>& piles, int i, int j) {
        if (i == j) return piles[i];
        if (memo[i][j]) return memo[i][j];
        memo[i][j] = max(presum[j] - presum[i-1] - solve(piles, i+1, j),
                         presum[j] - presum[i-1] - solve(piles, i, j-1));
        return memo[i][j];
    }
};
```

## Solution 2: DP

```cpp
bool stoneGame(vector<int>& piles) {
    int n = piles.size();
    piles.insert(piles.begin(), 0);

    vector<int> presum(n + 1);
    for (int i = 1; i <= n; ++i)
        presum[i] = presum[i - 1] + piles[i];

    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i)
        dp[i][i] = piles[i];

    for (int len = 2; len <= n; ++len) {
        for (int i = 1; i + len - 1 <= n; ++i) {
            int j = i + len - 1;
            dp[i][j] = max(presum[j] - presum[i - 1] - dp[i + 1][j],
                           presum[j] - presum[i - 1] - dp[i][j - 1]);
        }
    }

    return dp[1][n] > presum[n] - dp[1][n];
}
```

or

### 另一種 DP 定義
```
x x x [x x x x] x x
       i     j

dp[i][j] := 在 i 至 j 範圍內，最多可以比對方高多少分

dp[i][j] = max(p[i] - dp[i+1][j],
               p[j] - dp[i][j-1])
```

```cpp
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; ++i)
            dp[i][i] = piles[i];
        
        for (int len = 1; len < n; ++len) {
            for (int i = 0; i + len < n; ++i) {
                int j = i + len;
                dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
            }
        }
        return dp[0][n - 1] > 0;
    }
};
```

## Solution 3

```
X [O X O X O X O]
```

Alice 可以控制全選 X 或者 O，所以必勝。

```cpp
bool stoneGame(vector<int>& piles) {
    return true;
}
```
