# 474. Ones and Zeroes

## 解釋

最初以為是Greedy的問題，但原來不是，例子：

```
Input: ["111","1000","1000","1000"], m = 9, n = 3

Expected: 3
```

既然不是Greedy，那就是DP了，其實這是、兩種容量的 ```0/1背包``` 問題

### 狀態轉移方程：

```dp[k][i][j]``` 意思是考慮前 k 件物品，<strong>"數字0"</strong> 容量不超過 i、<strong>"數字1"</strong> 容量不超過 j 的最大價值（可以放的最大子集數量）

```cpp
if (i >= zeros && j >= ones)
    dp[k][i][j] = max(dp[k-1][i][j], dp[k-1][i-zeros][j-ones] + 1);
else
    dp[k][i][j] = dp[k-1][i][j];
```

## Code

這裡使用 "從後往前遍歷" 的方法，節省一個維度

```cpp
int findMaxForm(vector<string>& strs, int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (string& str : strs) {
        int zeros = 0, ones = 0;
        for (char& c : str) {
            if (c == '0')
                ++zeros;
            else
                ++ones;
        }

        for (int i = m; i >= zeros; --i) {
            for (int j = n; j >= ones; --j) {
                dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
            }
        }
    }
    return dp[m][n];
}
```
