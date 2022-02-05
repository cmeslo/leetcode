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

### Code，寫法一：

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
### Code，寫法二：

也可以不用 ```map```，用 ```vector<pair<int, int>>```：

```cpp
int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    int n = profit.size();
    vector<vector<int>> jobs;
    for (int i = 0; i < n; ++i)
        jobs.push_back({startTime[i], endTime[i], profit[i]});

    sort(jobs.begin(), jobs.end(), [&](auto& a, auto& b) { return a[1] < b[1]; });

    vector<pair<int, int>> dp; // {endTime, profit}
    dp.push_back({-1, 0});
    int pre = 0;
    for (int i = 0; i < n; ++i) {
        int cur = 0;
        // 方法一：
        // 這裡 pair 的第二個元素用INT_MAX，是為了讓找到的 it->first 一定要大於 jobs[i][0].
        // 如果是 {jobs[i][0], 0}，那麼可能會找到 it->first == jobs[i][0]，同時 it->second > 0 的 it
        // auto it = upper_bound(dp.begin(), dp.end(), make_pair(jobs[i][0], INT_MAX));

        // 方法二：
        // 也可以使用自定義比較，只比較 first 元素
        auto it = upper_bound(dp.begin(), dp.end(), make_pair(jobs[i][0], 0), [&](auto& a, auto& b) {
            return a.first < b.first;
        });
        cur = max(pre, prev(it)->second + jobs[i][2]);
        pre = cur;
        dp.push_back({jobs[i][1], cur});
    }
    return pre;
}
```
