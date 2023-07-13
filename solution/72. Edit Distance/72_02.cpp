class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        // 初始化邊界
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }
        
        // 遞推
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int r = word1[i-1] == word2[j-1] ? 0 : 1;
                
                dp[i][j] = min(dp[i-1][j-1] + r,
                                min(dp[i-1][j], dp[i][j-1]) + 1); 
            }
        }
        return dp[m][n];
    }
};
