# 871. Minimum Number of Refueling Stops

## Solution 1: heap

### 解釋

不斷從路過的加油站中，取出可以加最多油的那個站。

time: ```O(nlogn)```

### Code

```cpp
int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    int n = stations.size();

    auto cmp = [&](int i, int j) {
        return stations[i][1] < stations[j][1];
    };
    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
    int ans = 0;
    int cur = 0, fuel = startFuel;
    int i = 0;
    while (cur + fuel < target) {
        while (i < n && cur + fuel >= stations[i][0])
            pq.push(i++);
        if (pq.empty()) break;
        int index = pq.top(); pq.pop();
        fuel = fuel - (stations[index][0] - cur) + stations[index][1];
        cur = stations[index][0];
        ++ans;
    }
    return cur + fuel >= target ? ans : -1;
}
```

or

```cpp
int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    priority_queue<int> pq;
    int ans = 0, cur = startFuel, i = 0;

    while (cur < target) {
        while (i < stations.size() && cur >= stations[i][0])
            pq.push(stations[i++][1]);
        if (pq.empty()) return -1;
        cur += pq.top(), pq.pop();
        ++ans;
    }

    return ans;
}
```

## Solution 2: DP

### 解釋

```
經過前i個station，j次加油後可以到達的最遠距離:
dp[i][j] = max(dp[i][j], dp[i-1][j-1] + stations[i][1])

用後往前遍歷的方法、壓縮數組後:
dp[j] = max(dp[j], dp[j-1] + stations[i][1])
```

time: ```O(n^2)```

### Code

```cpp
int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    int n = stations.size();

    vector<long> dp(n + 1, startFuel); // dp[t] = t次加油後可以到達的最遠距離，t的範圍是 [0, n]
    for (int i = 0; i < n; ++i) {
        for (int t = i; t >= 0 && dp[t] >= stations[i][0]; --t) {
            dp[t + 1] = max(dp[t + 1], dp[t] + stations[i][1]);
        }
    }

    for (int t = 0; t <= n; ++t)
        if (dp[t] >= target) return t;
    return -1;
}
```

or

```cpp
int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    int n = stations.size();

    vector<long> dp(n + 1, startFuel); // dp[t] = t次加油後可以到達的最遠距離，t的範圍是 [0, n]
    for (int i = 1; i <= n; ++i) {
        int pos = stations[i - 1][0];
        int gas = stations[i - 1][1];
        for (int t = i; t >= 1 && dp[t - 1] >= pos; --t)
            dp[t] = max(dp[t], dp[t - 1] + gas);
    }

    for (int t = 0; t <= n; ++t)
        if (dp[t] >= target) return t;
    return -1;
}
```
