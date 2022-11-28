class Solution {
public:
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
};
