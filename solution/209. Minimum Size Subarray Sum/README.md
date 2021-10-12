# 209. Minimum Size Subarray Sum

## Solution: Two Pointers

### 寫法一：固定右指針 j

```cpp
int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    int ans = n + 1;
    for (int i = 0, j = 0; j < n; ++j) {
        sum += nums[j];
        while (sum >= target) {
            ans = min(ans, j - i + 1);
            sum -= nums[i++];
        }
    }
    return ans == n + 1 ? 0 : ans;
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
