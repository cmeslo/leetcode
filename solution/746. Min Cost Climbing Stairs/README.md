# 746. Min Cost Climbing Stairs

## Solution: DP

```dp[i] = min(dp[i-1], dp[i-2]) + cost```

而最後答案有可能是 ```dp[n]``` 或者是 ```dp[n-1]``` （從 n-1 跨到第 n+1 步）

```cpp
int minCostClimbingStairs(vector<int>& cost) {
    int dpi = 0, dpi_1 = 0, dpi_2 = 0;

    for (int c : cost) {
        dpi = min(dpi_1, dpi_2) + c;
        dpi_2 = dpi_1;
        dpi_1 = dpi;
    }

    return min(dpi, dpi_2);　// dpi_2就是原本的dpi_1
}
```
