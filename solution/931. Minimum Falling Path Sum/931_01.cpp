class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        vector<int> dp1(n), dp(n);
        for (int j = 0; j < n; ++j)
            dp1[j] = matrix[0][j];
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[j] = dp1[j] + matrix[i][j];
                if (j - 1 >= 0)
                    dp[j] = min(dp[j], dp1[j - 1] + matrix[i][j]);
                if (j + 1 < n)
                    dp[j] = min(dp[j], dp1[j + 1] + matrix[i][j]);
            }
            swap(dp1, dp);
        }
        return *min_element(dp1.begin(), dp1.end());
    }
};
