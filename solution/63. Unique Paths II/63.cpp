class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0 || obstacleGrid[0][0] == 1) return 0;
        
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
        
        for (int i = 0; i < obstacleGrid.size(); ++i)
        {
            for (int j = 0; j < obstacleGrid[i].size(); ++j)
            {
                if (obstacleGrid[i][j] == 1) continue;
                if (i == 0 && j == 0) {
                    dp[i][j] = 1;
                } else if (i == 0 && j > 0) {
                    dp[i][j] = dp[i][j - 1];
                } else if (j == 0 && i > 0) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        // for (int i = 0; i < obstacleGrid.size(); ++i) {
        //     for (int j = 0; j < obstacleGrid[i].size(); ++j) {
        //         cout << dp[i][j] << ", ";
        //     }
        //     cout << endl;
        // }
        
        // return dp[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
        return dp.back().back();
    }
};
