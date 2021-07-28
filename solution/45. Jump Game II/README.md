# 45. Jump Game II

## Solution 1: DP

```cpp
int jump(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n && j <= i + nums[i]; ++j)
            dp[j] = min(dp[j], dp[i] + 1);
    }
    return dp[n - 1];
}
```

## Solution 2: BFS

### 解釋：

每次都在當前 BFS 範圍內看，下一步最遠可以走多遠（下一次 BFS 的範圍）。

```
[2] 3  1  1  4
 2 [3  1] 1  4
 2  3  1 [1  4]
```

### Code:

```cpp
int jump(vector<int>& nums) {
    int start = 0, end = 0;
    int steps = 0;
    while (start <= end) {
        int end_next = end;
        for (int i = start; i <= end; ++i) {
            if (i == nums.size() - 1) return steps;
            end_next = max(end_next, i + nums[i]);
        }
        steps++;
        start = end + 1;
        end = end_next;
    }
    return -1;
}
```
