typedef pair<int, int> PII;

class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        unordered_map<int, unordered_map<int, int>> g; // node -> {next_node, next_weight}
        for (const auto& e : edges)
            g[e[0]][e[1]] = g[e[1]][e[0]] = e[2] + 1;
        
        unordered_map<int, int> dist;
        priority_queue<PII, vector<PII>, greater<>> pq; // {dist, node}
        pq.push({0, 0});
        while (!pq.empty()) {
            auto [d, cur] = pq.top(); pq.pop();
            if (dist.count(cur)) continue;
            dist[cur] = d;
            for (const auto& next : g[cur]) {
                int next_node = next.first;
                int next_weight = next.second;
                if (dist.count(next_node)) continue;
                if (d + next_weight <= maxMoves)
                    pq.push({d + next_weight, next_node});
            }
        }
        
        int ans = dist.size();
        for (const auto& e : edges) {
            int sum = 0;
            if (dist.count(e[0])) sum += maxMoves - dist[e[0]];
            if (dist.count(e[1])) sum += maxMoves - dist[e[1]];
            ans += min(sum, e[2]);
        }
        return ans;
    }
};
