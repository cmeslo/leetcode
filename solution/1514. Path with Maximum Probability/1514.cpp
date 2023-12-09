class Solution {
public:
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
};
