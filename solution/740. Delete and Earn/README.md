# 740. Delete and Earn

## Solution 1: DP

```cpp
int deleteAndEarn(vector<int>& nums) {
    map<int, int> m;
    for (int x : nums)
        m[x]++;

    vector<int> A;
    for (auto it : m)
        A.push_back(it.first);

    int n = A.size();
    vector<int> dp(n);
    dp[0] = A[0] * m[A[0]];
    for (int i = 1; i < n; ++i) {
        int pre = A[i - 1] + 1 == A[i] ? (i - 2 >= 0 ? dp[i - 2] : 0) : dp[i - 1];
        int cur = A[i] * m[A[i]];
        dp[i] = max(dp[i - 1], cur + pre);
    }

    return dp[n - 1];
}
```
