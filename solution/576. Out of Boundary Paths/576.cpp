class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        const int Mod = 1e9 + 7;
        vector<vector<int>> dp(m, vector<int>(n));
        auto temp = dp;
        for (int k = 0; k < maxMove; ++k) {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    long up = i - 1 < 0 ? 1 : dp[i - 1][j];
                    long down = i + 1 >= m ? 1 : dp[i + 1][j];
                    long left = j - 1 < 0 ? 1 : dp[i][j - 1];
                    long right = j + 1 >= n ? 1 : dp[i][j + 1];
                    temp[i][j] = (up + down + left + right) % Mod;
                }
            }
            swap(temp, dp);
        }
        return dp[startRow][startColumn];
    }
};
