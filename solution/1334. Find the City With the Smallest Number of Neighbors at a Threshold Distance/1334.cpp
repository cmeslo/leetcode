class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for (auto& e : edges) {
            int a = e[0], b = e[1], w = e[2];
            dist[a][b] = min(dist[a][b], w);
            dist[b][a] = min(dist[b][a], w);
        }
        
        for (int i = 0; i < n; ++i)
            dist[i][i] = 0;
        
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) continue;
                    if (dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
        
        int mn = INT_MAX, res = 0;
        vector<int> count(n);
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                if (dist[i][j] <= distanceThreshold)
                    ++cnt;
            }
            if (cnt <= mn) {
                mn = cnt;
                res = max(res, i);
            }
        }
        return res;
    }
};
