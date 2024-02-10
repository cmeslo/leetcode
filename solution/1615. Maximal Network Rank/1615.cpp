class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n, vector<int>(n));
        vector<int> D(n);
        for (auto& road : roads) {
            int a = road[0], b = road[1];
            adj[a][b]++;
            adj[b][a]++;
            D[a]++;
            D[b]++;
        }

        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                res = max(res, D[i] + D[j] - adj[i][j]);
            }
        }
        return res;
    }
};
