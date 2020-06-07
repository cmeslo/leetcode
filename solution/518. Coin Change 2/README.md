# 518. Coin Change 2

## Time Limit Exceeded 的解法

```cpp
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        _res = 0;
        backtrack(amount, coins, 0);
        return _res;
    }
    
private:
    int _res;
    
    void backtrack(int amount, const vector<int>& coins, int start) {
        if (amount < 0) return;
        if (amount == 0) {
            _res += 1;
            return;
        }
        for (int i = start; i < coins.size(); i++) {
            backtrack(amount-coins[i], coins, i);
        }
    }
};
```

## 518_01.cpp 用二維數組做DP的解法

row 是有多少種硬幣、由 0 至 coins.size() 個

column 是湊成的amount、由 0 至 amount

解釋可以參考: https://www.youtube.com/watch?v=DJ4a7cmjZY0

```cpp
int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));

    for (int j = 1; j <= amount; j++)
        dp[0][j] = 0;

    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= amount; j++) {
            int coin = coins[i-1];
            dp[i][j] = dp[i-1][j] + (j < coin ? 0 : dp[i][j-coin]);
        }
    }
    return dp[n][amount];
}
```


## 518_02.cpp

可以再優化，同樣思路、把二維數組化成一維。

```cpp
// Runtime: 4 ms
// Your runtime beats 99.30 % of cpp submissions.

int change(int amount, vector<int>& coins) {
    vector<int> dp(amount+1, 0);

    dp[0] = 1;
    for (int coin : coins) {
        for (int i = coin; i <= amount; i++) {
            dp[i] += dp[i-coin];
        }
    }
    return dp[amount];
}
```
