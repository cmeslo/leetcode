# 2369. Check if There is a Valid Partition For The Array

## Solution: DP

### 寫法一：
```cpp
bool validPartition(vector<int>& A) {
    int n = A.size();
    vector<int> dp(n + 1);
    dp[0] = true;
    dp[1] = false;
    dp[2] = A[0] == A[1];
    for (int i = 3; i <= n; ++i) {
        dp[i] = (A[i - 2] == A[i - 1] && dp[i - 2]) ||
            (A[i - 3] == A[i - 1] && A[i - 2] == A[i - 1] && dp[i - 3]) ||
            (A[i - 3] + 2 == A[i - 1] && A[i - 2] + 1 == A[i - 1] && dp[i - 3]);
    }
    return dp[n];
}
```

### 寫法二：
```cpp
bool validPartition(vector<int>& nums) {
    int n = nums.size();
    nums.insert(nums.begin(), -1);
    vector<bool> dp(n + 1);
    dp[0] = true;
    for (int i = 1; i <= n; ++i) {
        if (i - 1 >= 0) {
            if (nums[i-1] == nums[i])
                dp[i] = dp[i - 2];
        }
        if (i - 2 >= 0) {
            if ((nums[i-2] == nums[i-1] && nums[i-1] == nums[i])
                || (nums[i-2] + 1 == nums[i-1] && nums[i-1] + 1 == nums[i]))
                dp[i] = dp[i] || dp[i - 3];
        }
    }
    return dp[n];
}
```
