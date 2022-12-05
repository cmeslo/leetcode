# 354. Russian Doll Envelopes

LIS problem.

## Solution 1: DP

- time complexity: O(n^2)

```cpp
int maxEnvelopes(vector<vector<int>>& envelopes) {
    int n = envelopes.size();
    sort(begin(envelopes), end(envelopes));

    int ans = 0;
    vector<int> dp(n, 1);
    for (int i = 0; i < n; ++i) {
        for (int j = i - 1; j >= 0; --j) {
            if (envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }

    return ans;
}
```

## Solution 2

```cpp
int maxEnvelopes(vector<vector<int>>& envelopes) {
    sort(envelopes.begin(), envelopes.end(), [](auto& a, auto& b) {
        return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
    });
    vector<int> LIS;
    for (auto& e : envelopes) {
        auto it = lower_bound(LIS.begin(), LIS.end(), e[1]);
        if (it == LIS.end())
            LIS.push_back(e[1]);
        else
            *it = e[1];
    }
    return LIS.size();
}
```
