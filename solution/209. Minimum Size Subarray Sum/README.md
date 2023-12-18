# 209. Minimum Size Subarray Sum

## Solution: Two Pointers

### 寫法一：固定右指針 j

```cpp
int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int res = n + 1;
    for (int i = 0, j = 0; j < n; ++j) {
        target -= nums[j];
        while (target <= 0) {
            res = min(res, j - i + 1);
            target += nums[i++];
        }
    }
    return res == n + 1 ? 0 : res;
}
```

### 寫法二：固定左指針 i

```cpp
int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int ans = n + 1, sum = 0;
    for (int i = 0, j = 0; i < n; ++i) {
        while (j < n && sum < target)
            sum += nums[j++];
        if (sum >= target)
            ans = min(ans, j - i);
        sum -= nums[i];
    }
    return ans == n + 1 ? 0 : ans;
}
```
