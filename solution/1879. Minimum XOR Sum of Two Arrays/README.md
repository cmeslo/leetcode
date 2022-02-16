# 1879. Minimum XOR Sum of Two Arrays

## Solution 1: DP + 狀態壓縮

```cpp
// Runtime: 296 ms

int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    vector<int> dp(1 << m, INT_MAX / 2);
    vector<int> dp2;
    dp[0] = 0;
    for (int j = 0; j < m; ++j) {
        dp2 = dp;
        for (int state = 0; state < (1 << m); ++state) {
            for (int i = 0; i < m; ++i) {
                if ((state >> i) & 1) {
                    dp[state] = min(dp[state], dp2[state - (1 << i)] + (nums1[i] ^ nums2[j]));
                }
            }
        }
    }
    return dp[(1 << m) - 1];
}
```

## Solution 2: DP + 狀態壓縮 + Gospers Hack

```cpp
// Runtime: 37 ms

int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    vector<int> dp(1 << m, INT_MAX / 2);
    vector<int> dp2;
    dp[0] = 0;
    for (int j = 0; j < m; ++j) {
        dp2 = dp;
        int k = j + 1;
        int state = (1 << k) - 1;            
        while (state < (1 << m))
        {
            for (int i = 0; i < m; ++i) {
                if ((state >> i) & 1) {
                    dp[state] = min(dp[state], dp2[state - (1 << i)] + (nums1[i] ^ nums2[j]));
                }
            }

            int c = state & - state;
            int r = state + c;
            state = (((r ^ state) >> 2) / c) | r;
        }
    }
    return dp[(1 << m) - 1];
}
```

## Solution 3: Dijkstra

```
00000 -> ... -> 11111
```

```cpp
int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
    using PII = pair<int, int>;
    int n = nums1.size();

    priority_queue<PII, vector<PII>, greater<>> pq; // {cost, state}
    pq.push({0, 0});
    vector<bool> visited(1 << n, false);

    while (!pq.empty()) {
        auto [cost, state] = pq.top(); pq.pop();
        if (visited[state]) continue;
        visited[state] = true;

        int j = __builtin_popcount(state);
        if (j == n) return cost;

        for (int i = 0; i < n; ++i) {
            if ((state >> i) & 1) continue;
            int nextState = state + (1 << i);
            if (visited[nextState]) continue;
            int nextCost = cost + (nums1[i] ^ nums2[j]);
            pq.push({nextCost, nextState});
        }
    }
    return -1;
}
```
