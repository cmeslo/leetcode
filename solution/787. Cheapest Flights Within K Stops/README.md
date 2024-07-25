# 787. Cheapest Flights Within K Stops

## Solution 1: DFS + 剪枝 (787_01.cpp)

```cpp
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {

        int LIMIT = 100;
        graph = vector<unordered_set<int>>(LIMIT);
        cost = vector<vector<int>>(LIMIT, vector<int>(LIMIT, -1));
        min_price = INT_MAX;
        
        for (const vector<int>& f : flights) {
            graph[f[0]].insert(f[1]);
            cost[f[0]][f[1]] = f[2];
        }
        
        unordered_set<int> visited({src});
        
        dfs(src, dst, 0, K+1, visited);
        return min_price == INT_MAX ? -1: min_price;
    }
    
private:
    vector<unordered_set<int>> graph;
    vector<vector<int>> cost;
    int min_price;
    
    void dfs(int node, int dst, int curr_cost, int K, unordered_set<int>& visited) {
        if (K < 0) return;
        if (node == dst) {
            min_price = curr_cost;
            return;
        }
        
        for (int child : graph[node]) {
            int new_cost = curr_cost + cost[node][child];
            
            if (visited.count(child) || new_cost > min_price) continue;
            visited.insert(child);
            dfs(child, dst, new_cost, K-1, visited);
            visited.erase(child);
        }
    }
};
```

## Solution 2: Bellman-Ford algorithm (787_02.cpp)

```cpp
// Bellman-Ford algorithm
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
    vector<vector<int>> dp(K+2, vector<int>(n, 1e9)); //這裡不用INT_MAX，是怕做加法後會越界

    dp[0][src] = 0;
    for (int i = 1; i <= K+1; ++i) {
        dp[i][src] = 0;
        for (const vector<int>& f : flights) {
            int from_place = f[0], to_place = f[1], cost = f[2];
            dp[i][to_place] = min(dp[i][to_place], dp[i-1][from_place] + cost);
        }
    }
    return (dp[K+1][dst] >= 1e9) ? -1 : dp[K+1][dst];
}
```
有關算法可以參考：

https://www.youtube.com/watch?v=obWXjtg0L64

也可以用 Dijkstra 算法做。

Dijkstra 和 Bellman-Ford 兩種算法比較相似，具體對比可以看以下網址:

https://blog.csdn.net/mmy1996/article/details/52225893

## Solution 3: Dijkstra algorithm (787_03.cpp)

```cpp
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    using ai3 = array<int, 3>; // {cost, k, node}
    const int INF =  1e9;
    
    vector<vector<pair<int, int>>> adj(n);
    for (auto& f : flights) {
        int a = f[0], b = f[1], price = f[2];
        adj[a].push_back({b, price});
    }
    
    priority_queue<ai3, vector<ai3>, greater<>> pq;
    vector<vector<int>> cost(n, vector<int>(k + 3, INF));
    pq.push({0, k + 2, src});
    while (!pq.empty()) {
        auto [c, remain, node] = pq.top(); pq.pop();
        if (c > cost[node][remain]) continue;
        if (node == dst) return c;
        cost[node][remain] = c;
        if (remain - 1 <= 0) continue;
        for (auto& [next, price] : adj[node]) {
            if (c + price >= cost[next][remain - 1]) continue;
            cost[next][remain - 1] = c + price;
            pq.push({c + price, remain - 1, next});
        }
    }
    return -1;
}
```

## Solution 4: BFS (787_04.cpp)

接近雙百

```cpp
// Runtime: 11 ms, Your runtime beats 92.86 % of cpp submissions.
// Memory Usage: 16.4 MB, Your memory usage beats 93.59 % of cpp submissions.

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    using pii = pair<int, int>; // {cost, node}
    using ai3 = array<int, 3>;
    queue<pii> q;
    
    vector<vector<pii>> adj(n);
    for (auto& f : flights) {
        int a = f[0], b = f[1], price = f[2];
        adj[a].push_back({b, price});
    }
    
    k += 1;
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    q.push({0, src});
    while (!q.empty() && k--) {
        for (int i = q.size(); i > 0; --i) {
            auto [cost, node] = q.front(); q.pop();
            for (auto& [next, price] : adj[node]) {
                if (cost + price >= dist[next]) continue;
                dist[next] = cost + price;
                q.push({dist[next], next});
            }
        }
    }
    return dist[dst] == INT_MAX ? -1 : dist[dst];
}
```
