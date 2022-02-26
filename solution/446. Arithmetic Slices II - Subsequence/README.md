# 446. Arithmetic Slices II - Subsequence

```
dp[i][diff] := 以 nums[i] 為結尾，公差為 diff 的 sequence (元素個數 >=2) 數目
```

```cpp
int numberOfArithmeticSlices(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;
    vector<unordered_map<long, int>> dp(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            long diff = (long)nums[i] - nums[j];
            dp[i][diff] += dp[j][diff] + 1;
            ans += dp[j][diff];
        }
    }
    return ans;
}
```
