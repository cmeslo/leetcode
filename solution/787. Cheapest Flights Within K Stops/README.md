# 787. Cheapest Flights Within K Stops

## 787_01.cpp
DFS + 剪枝

## Bellman-Ford algorithm (787_02.cpp)

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

## Dijkstra algorithm (787_03.cpp)

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
