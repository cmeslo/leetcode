# 1584. Min Cost to Connect All Points

## Solution 1: Prim's alogrithm (version 1)

time: ```O(n^2 log(n^2))```

```cpp
// Runtime: 332 ms, Your runtime beats 75.53 % of cpp submissions.
// Memory Usage: 130.5 MB, Your memory usage beats 23.26 % of cpp submissions.

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
// Runtime: 341 ms, Your runtime beats 74.61 % of cpp submissions.
// Memory Usage: 130.5 MB, Your memory usage beats 22.65 % of cpp submissions.

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

time: ```O(n^2)```

```cpp
// Runtime: 85 ms, Your runtime beats 99.12 % of cpp submissions.
// Memory Usage: 10.2 MB, Your memory usage beats 95.88 % of cpp submissions.

int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();

    int res = 0;
    vector<int> minDist(n, INT_MAX);
    vector<bool> visited(n, false);
    minDist[0] = 0;

    for (int connected = 0; connected < n; ++connected) {
        // 1. 找到下一個要接入MST的節點
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

        // 2. 接入 next 節點後，更新其他尚未接入節點的距離
        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            minDist[i] = min(minDist[i], abs(points[i][0] - points[next][0]) + abs(points[i][1] - points[next][1]));
        }
    }

    return res;
}
```

## Solution 3: kruskal's algorithm

time: ```O(k log(E^2))```

```cpp
// Runtime: 261 ms, Your runtime beats 83.65 % of cpp submissions.
// Memory Usage: 79.4 MB, Your memory usage beats 35.50 % of cpp submissions.

class Solution {
private:
    int father[1001];
    
    int FindFather(int i) {
        if (father[i] != i)
            father[i] = FindFather(father[i]);
        return father[i];
    }
    
    void Union(int i, int j) {
        i = FindFather(i);
        j = FindFather(j);
        if (i < j)
            father[j] = i;
        else
            father[i] = j;
    }
    
public:
    // kruskal's algorithm
    int minCostConnectPoints(vector<vector<int>>& points) {
        using a3 = array<int, 3>;
        int n = points.size();
        if (n == 1) return 0;
        
        for (int i = 0; i < n; ++i)
            father[i] = i;
        
        vector<a3> edges;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({dist, i, j});
            }
        }
        
        priority_queue<a3, vector<a3>, greater<>> pq(edges.begin(), edges.end());
        int res = 0;
        int count = 0;
        while (!pq.empty()) {
            auto e = pq.top(); pq.pop();
            int d = e[0], i = e[1], j = e[2];
            if (FindFather(i) != FindFather(j)) {
                Union(i, j);
                res += d;
                if (++count == n - 1) return res;
            }
        }
        return -1;
    }
};
```
