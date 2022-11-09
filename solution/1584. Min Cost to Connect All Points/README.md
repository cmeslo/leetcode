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

or

```cpp
int minCostConnectPoints(vector<vector<int>>& points) {
    using pii = pair<int, int>;

    int n = points.size();
    vector<vector<pii>> adj(n);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int cost = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
            adj[i].push_back({cost, j});
            adj[j].push_back({cost, i});
        }
    }

    int res = 0, count = 0;
    priority_queue<pii, vector<pii>, greater<>> pq;
    vector<bool> visited(n, false);
    pq.push({0, 0});
    while (!pq.empty()) {
        auto [cost, i] = pq.top(); pq.pop();
        if (visited[i]) continue;
        visited[i] = true;
        res += cost;
        if (++count == n) break;
        for (auto [d, j] : adj[i]) {
            if (visited[j]) continue;
            pq.push({d, j});
        }
    }
    return res;
}
```

## Solution 2: Prim's alogrithm (version 2)

```cpp
int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();

    int res = 0;
    vector<int> minDist(n, INT_MAX);
    vector<bool> visited(n, false);
    minDist[0] = 0;

    for (int connected = 0; connected < n; ++connected) {
        int next = -1, nextDist = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            if (minDist[i] < nextDist) {
                next = i;
                nextDist = minDist[next];
            }
        }
        visited[next] = true;
        res += nextDist;

        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            minDist[i] = min(minDist[i], abs(points[i][0] - points[next][0]) + abs(points[i][1] - points[next][1]));
        }
    }

    return res;
}
```
