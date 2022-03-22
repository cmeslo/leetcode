# 882. Reachable Nodes In Subdivided Graph

## Solution: Dijkstra's algorithm

1. 先用 Dijkstra's algorithm 去找、到達其他大節點的最短路；

2. 然後遍歷所有的邊，使用可達到的大節點，去計算覆蓋到的小節點；

3. 如果兩個大節點都可達到、並且中間發生重疊，代表該條邊上的所有小節點都是可以覆蓋的。

### 寫法一

```cpp
// 289 ms, Your runtime beats 56.80 % of cpp submissions.
// Your memory usage beats 80.58 % of cpp submissions.

int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
    unordered_map<int, unordered_map<int, int>> g; // node -> {next_node, next_weight}
    for (const auto& e : edges)
        g[e[0]][e[1]] = g[e[1]][e[0]] = e[2] + 1;

    unordered_map<int, int> dist;
    priority_queue<PII, vector<PII>, greater<>> pq; // {dist, node}
    pq.push({0, 0});
    while (!pq.empty()) {
        auto [d, cur] = pq.top(); pq.pop();
        if (dist.count(cur)) continue;
        dist[cur] = d;
        for (const auto& next : g[cur]) {
            int next_node = next.first;
            int next_weight = next.second;
            if (dist.count(next_node)) continue;
            if (d + next_weight <= maxMoves)
                pq.push({d + next_weight, next_node});
        }
    }

    int ans = dist.size();
    for (const auto& e : edges) {
        int sum = 0;
        if (dist.count(e[0])) sum += maxMoves - dist[e[0]];
        if (dist.count(e[1])) sum += maxMoves - dist[e[1]];
        ans += min(sum, e[2]);
    }
    return ans;
}
```

### 寫法二

```cpp
// 140 ms, Your runtime beats 97.57 % of cpp submissions.
// Your memory usage beats 85.44 % of cpp submissions.

int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
    using pii = pair<int, int>;
    vector<vector<pii>> adj(n);
    for (auto& e : edges) {
        int a = e[0], b = e[1], w = e[2];
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    vector<int> dist(n, INT_MAX);
    priority_queue<pii, vector<pii>, greater<>> pq;
    pq.push({0, 0});
    while (!pq.empty()) {
        auto [d, node] = pq.top(); pq.pop();
        if (d >= dist[node]) continue;
        dist[node] = d;
        for (auto& [next, w] : adj[node]) {
            if (d + w + 1 >= dist[next] || d + w + 1 > maxMoves) continue;
            pq.push({d + w + 1, next});
        }
    }

    int ans = 0;
    for (auto& e : edges) {
        int a = e[0], b = e[1], w = e[2];
        ans += min(w, max(0, maxMoves - dist[a]) + max(0, maxMoves - dist[b]));
    }
    for (int i = 0; i < n; ++i)
        ans += dist[i] != INT_MAX;
    return ans;
}
```
