# 743. Network Delay Time

## Solution: Dijkstra's algorithm

```cpp
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
