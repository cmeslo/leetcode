# 1235. Maximum Profit in Job Scheduling

## Solution: Sort by endTime + binary search

### 思考：
```
------
   ----j
     -------
         -------i

definition 1 (may TLE, not work):
dp[i] = max{dp[j] + profit[i]} for j = ...
loop -> n^2

definition 2:
dp[t] := by the time t, the max profit we can got.
dp[i] = max(dp[j] + val[i], dp[i-1])
```

### Code

```cpp
int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    int n = profit.size();
    vector<vector<int>> jobs;
    for (int i = 0; i < n; ++i)
        jobs.push_back({startTime[i], endTime[i], profit[i]});

    sort(jobs.begin(), jobs.end(), [&](auto& a, auto& b) { return a[1] < b[1]; });

    map<int, int> dp; // {endTime, profit}
    dp[-1] = 0;
    int pre = 0;
    for (int i = 0; i < n; ++i) {
        int cur = 0;
        auto it = dp.upper_bound(jobs[i][0]);
        cur = max(pre, prev(it)->second + jobs[i][2]);
        dp[jobs[i][1]] = pre = cur;
    }
    return pre;
}
```

如果不放 DP[-1] = 0，可以這樣寫：

```cpp
map<int, int> dp; // {endTime, profit}
int pre = 0;
for (int i = 0; i < n; ++i) {
    int cur = 0;
    auto it = dp.upper_bound(jobs[i][0]);
    if (it == dp.begin())
        cur = max(pre, jobs[i][2]);
    else
        cur = max(pre, prev(it)->second + jobs[i][2]);
    dp[jobs[i][1]] = pre = cur;
}
```
