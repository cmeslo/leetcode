# 743. Network Delay Time

## Solution: Dijkstra's algorithm

```cpp
// Runtime: 115 ms, Your runtime beats 98.37 % of cpp submissions.
// Memory Usage: 40 MB, Your memory usage beats 67.63 % of cpp submissions.

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    using pii = pair<int, int>;
    vector<vector<pii>> adj(n + 1);
    for (auto& t : times) {
        adj[t[0]].push_back({t[1], t[2]});
    }

    priority_queue<pii, vector<pii>, greater<>> pq;
    vector<int> dist(n + 1, INT_MAX);
    dist[k] = 0;
    pq.push({0, k});
    while (!pq.empty()) {
        auto [d, node] = pq.top(); pq.pop();
        if (d > dist[node]) continue;
        for (auto& [next, w] : adj[node]) {
            if (w + d >= dist[next]) continue;
            dist[next] = w + d;
            pq.push({w + d, next});
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (dist[i] == INT_MAX)
            return -1;
        ans = max(ans, dist[i]);
    }
    return ans;
}
```

or

```cpp
// Runtime: 124 ms, Your runtime beats 95.70 % of cpp submissions.
// Memory Usage: 39.9 MB, Your memory usage beats 77.33 % of cpp submissions.

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    using pii = pair<int, int>;
    vector<vector<pii>> adj(n + 1);
    for (auto& t : times) {
        adj[t[0]].emplace_back(t[1], t[2]);
    }

    priority_queue<pii, vector<pii>, greater<>> pq;
    vector<int> dist(n + 1, INT_MAX);
    dist[k] = 0;
    pq.emplace(0, k);

    int ans = 0;
    while (!pq.empty()) {
        auto [d, node] = pq.top(); pq.pop();
        if (d > dist[node]) continue;
        ans = max(ans, dist[node]);
        if (--n == 0) return ans;
        for (auto& [next, w] : adj[node]) {
            if (w + d >= dist[next]) continue;
            pq.emplace(dist[next] = w + d, next);
        }
    }
    return -1;
}
```
