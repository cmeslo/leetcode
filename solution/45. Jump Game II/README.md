# 45. Jump Game II

## Solution 1: DP

```cpp
int jump(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n && j <= i + nums[i]; ++j)
            dp[j] = min(dp[j], dp[i] + 1);
    }
    return dp[n - 1];
}
```
