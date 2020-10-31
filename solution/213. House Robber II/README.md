# 213. House Robber II

```cpp
int rob(vector<int>& nums) {
    int n = nums.size();
    if (n <= 3) return *max_element(begin(nums), end(nums));

    int ans = 0;
    vector<int> dp(n, 0);

    dp[0] = nums[0];
    dp[1] = max(dp[0], nums[1]);
    for (int i = 2; i < n - 1; ++i)
        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    ans = dp[n - 2];

    fill(begin(dp), end(dp), 0);
    dp[1] = nums[1];
    for (int i = 2; i < n; ++i)
        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    ans = max(ans, dp[n - 1]);

    return ans;
}
```

寫得簡潔一點：

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n <= 3)
            return *max_element(begin(nums), end(nums));
        else
            return max(rob(nums, 0, n - 1), rob(nums, 1, n));
    }
    
private:
    int rob(vector<int>& nums, int start, int end) {
        int pre = nums[start];
        int last = max(pre, nums[start + 1]);
        
        int ans = 0;
        for (int i = start + 2; i < end; ++i) {
            ans = max(pre + nums[i], last);
            pre = last;
            last = ans;
        }
        
        return ans;
    }
};
```
