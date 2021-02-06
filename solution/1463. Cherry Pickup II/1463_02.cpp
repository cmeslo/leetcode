class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int h = grid.size(), w = grid[0].size();
        vector<vector<int>> dp(w + 2, vector<int>(w + 2));
        
        for (int y = h; y >= 1; --y) {
            vector<vector<int>> tmp(w + 2, vector<int>(w + 2));
            for (int x1 = 1; x1 <= w; ++x1) {
                for (int x2 = 1; x2 <= w; ++x2) {
                    int cur = grid[y - 1][x1 - 1] + (x1 != x2) * grid[y - 1][x2 - 1];
                    int& ans = tmp[x1][x2];
                    for (int d1 = -1; d1 <= 1; ++d1)
                        for (int d2 = -1; d2 <= 1; ++d2)
                            ans = max(ans, cur + dp[x1 + d1][x2 + d2]);
                }
            }
            dp.swap(tmp);
        }
        
        return dp[1][w];
    }
};
