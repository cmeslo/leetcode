class Solution {
public:
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
};
