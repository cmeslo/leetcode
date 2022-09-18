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

## Solution 2: DP

```cpp
int deleteAndEarn(vector<int>& nums) {
    int n = 10001;
    vector<int> gain(n);
    for (int x : nums)
        gain[x] += x;

    vector<int> dp(n);
    dp[1] = gain[1];
    for (int i = 2; i < n; ++i) {
        dp[i] = max(dp[i - 1], gain[i] + dp[i - 2]);
    }
    return dp[n - 1];
}
```

or

優化空間：

```cpp
int deleteAndEarn(vector<int>& nums) {
    int n = 10001;
    vector<int> gain(n);
    for (int x : nums)
        gain[x] += x;

    int a = 0; // 取nums[i]所能獲得的最大收益
    int b = 0; // 不取nums[i]所能獲得的最大收益
    for (int i = 0; i < n; ++i) {
        int a2 = a, b2 = b;
        a = b2 + gain[i];
        b = max(a2, b2);
    }
    return max(a, b);
}
```
