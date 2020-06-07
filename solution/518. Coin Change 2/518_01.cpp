class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp = vector<vector<int>>(n+1, vector<int>(amount+1));
        
        for (int j = 1; j <= amount; j++)
            dp[0][j] = 0;
        
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                int coin = coins[i-1];
                dp[i][j] = dp[i-1][j] + (j < coin ? 0 : dp[i][j-coin]);
            }
        }
        return dp[n][amount];
    }
};
