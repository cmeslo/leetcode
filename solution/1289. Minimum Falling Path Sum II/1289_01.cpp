class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        const int m = A.size(), n = A[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        for (int j = 0; j < n; ++j)
            dp[0][j] = A[0][j];
        
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (j == k) continue;
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + A[i][j]);
                }
            }
        }
        
        int res = INT_MAX;
        for (int j = 0; j < n; ++j)
            res = min(res, dp[n - 1][j]);
        return res;
    }
};
