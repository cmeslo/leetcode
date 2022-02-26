# 446. Arithmetic Slices II - Subsequence

## Solution 1: 現在會 TLE

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

## Solution 2:

```
dp[j][i] := 以 nums[j]，nums[i] 為最後兩項的等差數列的個數
```

```cpp
int numberOfArithmeticSlices(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, vector<int>> pos;
    for (int i = 0; i < n; ++i)
        pos[nums[i]].push_back(i);

    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            long val = nums[j] * 2L - nums[i];
            if (val < INT_MIN || val > INT_MAX) continue;
            for (int k : pos[val]) {
                if (k < j)
                    dp[j][i] += dp[k][j] + 1;
            }
        }
    }

    int res = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < i; ++j)
            res += dp[j][i];
    return res;
}

// nums[k], nums[j], nums[i]
// nums[k] - nums[j] = nums[j] - nums[i]
// nums[k] = nums[j] + nums[j] - nums[i]

```
