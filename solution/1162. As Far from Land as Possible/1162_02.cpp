class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        const int INF = 200;
        
        int n = grid.size(), res = 0;
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, INF));
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                bool water = grid[i - 1][j - 1] == 0;
                if (water) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        for (int i = n; i >= 1; --i) {
            for (int j = n; j >= 1; --j) {
                bool water = grid[i - 1][j - 1] == 0;
                if (water) {
                    dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
                    dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
                    res = max(res, dp[i][j]);
                }
            }
        }
        return res == 0 || res == INF ? -1 : res;
    }
};
