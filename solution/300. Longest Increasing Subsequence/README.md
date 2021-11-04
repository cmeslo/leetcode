# 300. Longest Increasing Subsequence

## Solution 1: DP

time: ```O(n^2)```

```cpp
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size(), ans = 0;
    vector<int> dp(n, 1);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[j] < nums[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }

    return ans;
}
```

## Solution 2: 棧

time: ```O(nlogn)```

```cpp
int lengthOfLIS(vector<int>& nums) {
    vector<int> q;
    for (int x : nums) {
        auto it = lower_bound(begin(q), end(q), x);
        if (it == q.end())
            q.push_back(x);
        else
            *it = x;
    }
    return q.size();
}
```
