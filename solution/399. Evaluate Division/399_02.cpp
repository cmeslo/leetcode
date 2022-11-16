class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, int> m;
        int i = 0;
        for (auto& e : equations) {
            if (!m.count(e[0]))
                m[e[0]] = i++;
            if (!m.count(e[1]))
                m[e[1]] = i++;
        }
        
        int n = m.size();
        const double INF = 1000.0;
        vector<vector<double>> dist(n, vector<double>(n, INF));
        for (int i = 0; i < n; ++i) {
            dist[i][i] = 1.0;
        }
        
        for (int i = 0; i < equations.size(); ++i) {
            int a = m[equations[i][0]], b = m[equations[i][1]];
            dist[a][b] = values[i];
            dist[b][a] = 1.0 / values[i];
        }
        
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][k] == INF || dist[k][j] == INF) continue;
                    dist[i][j] = dist[i][k] * dist[k][j];
                }
            }
        }
        
        vector<double> ans;
        for (auto& q : queries) {
            if (!m.count(q[0]) || !m.count(q[1])) {
                ans.push_back(-1.0);
                continue;
            }
            int a = m[q[0]], b = m[q[1]];
            ans.push_back(dist[a][b] == INF ? -1.0 : dist[a][b]);
        }
        return ans;
    }
};
