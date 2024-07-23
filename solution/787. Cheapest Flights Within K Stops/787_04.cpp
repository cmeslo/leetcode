class Solution {
public:
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
};
