class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long>> dist(26, vector<long>(26, INT_MAX));
        for (int i = 0; i < cost.size(); ++i) {
            int a = original[i] - 'a', b = changed[i] - 'a';
            dist[a][b] = min(dist[a][b], 1L * cost[i]);
        }
        
        for (int i = 0; i < 26; ++i)
            dist[i][i] = 0;
        
        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        
        long res = 0;
        for (int i = 0; i < target.size(); ++i) {
            int a = source[i] - 'a', b = target[i] - 'a';
            if (dist[a][b] == INT_MAX) return -1;
            res += dist[a][b];
        }
        return res;
    }
};
