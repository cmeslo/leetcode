class Solution {
public:
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
};
