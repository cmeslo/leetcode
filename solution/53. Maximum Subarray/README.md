# 53. Maximum Subarray

## Solution: Kadane's algorithm

```cpp
int maxSubArray(vector<int>& nums) {
    int ans, sum;
    ans = sum = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        sum = max(sum + nums[i], nums[i]);
        ans = max(ans, sum);
    }

    return ans;
}
```
