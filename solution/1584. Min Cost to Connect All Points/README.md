# 1584. Min Cost to Connect All Points

## Solution 1: Prim's alogrithm (version 1)

time: ```O(n^2 log(n^2))```

```cpp
int minCostConnectPoints(vector<vector<int>>& points) {
    using pii = pair<int, int>;
    int n = points.size();
    vector<vector<pii>> adj(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            int cost = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
            adj[i].push_back({cost, j});
        }
    }

    priority_queue<pii, vector<pii>, greater<>> pq; // {cost, point}
    vector<bool> visited(n, false);
    pq.push({0, 0});
    int count = 0, sum = 0;
    while (!pq.empty()) {
        auto [c, i] = pq.top(); pq.pop();
        if (visited[i]) continue;
        visited[i] = true;
        sum += c;
        if (++count == n) break;
        for (auto [d, j] : adj[i]) {
            if (visited[j]) continue;
            pq.push({d, j});
        }
    }
    return sum;
}
```
