class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 0 || n == 0) return 1;
        
        vector<int> dp(m*n, 0);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int cur = i*m + j;
                if (i == 0 || j == 0) {
                    dp[cur] = 1; continue;
                }
                dp[cur] = dp[cur-m] + dp[cur-1];
            }
        }
        return dp[m*n-1];
    }
};
