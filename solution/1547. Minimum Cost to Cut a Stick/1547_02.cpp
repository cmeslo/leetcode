class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        
        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, INT_MAX));
        for (int i = 0; i + 1 < m; ++i) {
            dp[i][i + 1] = 0;
        }
        for (int len = 3; len <= m; ++len) {
            for (int i = 0; i + len - 1 < m; ++i) {
                int j = i + len - 1;
                for (int k = i + 1; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], cuts[j] - cuts[i] + dp[i][k] + dp[k][j]);
                }
            }
        }
        return dp[0][m - 1];
    }
};


// x x x | x x x x x
// i   k           j

// (j - i) + dfs(i, k) + dfs(k, j)

