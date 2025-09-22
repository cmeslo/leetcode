# 1514. Path with Maximum Probability

## Solution: Dijkstra's algorithm

```cpp
double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
    using pdi = pair<double, int>;
    vector<vector<pair<int, double>>> adj(n);
    for (int i = 0; i < edges.size(); ++i) {
        int a = edges[i][0], b = edges[i][1];
        double p = succProb[i];
        adj[a].push_back({b, p});
        adj[b].push_back({a, p});
    }
    
    priority_queue<pdi> pq;
    vector<double> dist(n);
    pq.push({1.0, start});
    while (!pq.empty()) {
        auto [p, node] = pq.top(); pq.pop();
        if (node == end) return p;
        if (dist[node] >= p) continue;
        dist[node] = p;
        for (auto& [next, p2] : adj[node]) {
            double pNext = p * p2;
            if (pNext > dist[next]) {
                pq.push({pNext, next});
            }
        }
    }
    return 0.0;
}
```

or

```cpp
double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
    vector<vector<pair<int, double>>> adj(n);
    for (int i = 0; i < edges.size(); ++i) {
        int a = edges[i][0], b = edges[i][1];
        double p = succProb[i];
        adj[a].push_back({b, p});
        adj[b].push_back({a, p});
    }
    
    vector<double> cost(n);
    priority_queue<pair<double, int>> pq;
    cost[start_node] = 1;
    pq.push({1, start_node});
    while (!pq.empty()) {
        auto [p, node] = pq.top(); pq.pop();
        if (p < cost[node]) continue;
        if (node == end_node) return p;
        for (auto [next, p_next] : adj[node]) {
            p_next *= p;
            if (p_next <= cost[next]) continue;
            cost[next] = p_next;
            pq.push({p_next, next});
        }
    }
    return 0;
}
```
