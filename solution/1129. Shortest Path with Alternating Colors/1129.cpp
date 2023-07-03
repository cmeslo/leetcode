// Runtime: 12 ms, Your runtime beats 99.16 % of cpp submissions.
// Memory Usage: 14.7 MB, Your memory usage beats 86.27 % of cpp submissions.

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> dist(2, vector<int>(n, INT_MAX));
        vector<vector<int>> adj[2];
        adj[0].resize(n);
        adj[1].resize(n);
        for (auto& e : redEdges) {
            adj[0][e[0]].push_back(e[1]);
        }
        for (auto& e : blueEdges) {
            adj[1][e[0]].push_back(e[1]);
        }
        
        queue<pair<int, int>> q; // node, color_of_pre_edge
        q.push({0, 0}); // 0, red
        q.push({0, 1}); // 0, blue
        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [node, preColor] = q.front(); q.pop();
                if (dist[preColor][node] <= steps) continue;
                dist[preColor][node] = steps;
                int color = 1 - preColor;
                for (int next : adj[color][node]) {
                    if (dist[color][next] <= steps) continue;
                    q.emplace(next, color);
                }
            }
            steps++;
        }
        
        for (int i = 0; i < n; ++i) {
            int mn = min(dist[0][i], dist[1][i]);
            dist[0][i] = mn == INT_MAX ? -1 : mn;
        }
        
        return dist[0];
    }
};
