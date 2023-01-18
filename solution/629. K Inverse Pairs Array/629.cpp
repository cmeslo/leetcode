class Solution {
public:
    int kInversePairs(int n, int k) {
        const int Mod = 1e9 + 7;
        vector<vector<long>> dp(n + 1, vector<long>(k + 1));
        
        for (int i = 0; i <= n; ++i)
            dp[i][0] = 1;
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                // for (int m = 0; m <= min(j, i - 1); ++m) {
                //     dp[i][j] += dp[i - 1][j - m];
                // }
                if (j >= i)
                    dp[i][j] = (dp[i - 1][j] - dp[i - 1][j - i] + dp[i][j - 1] + Mod) % Mod;
                else
                    dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % Mod;
            }
        }
        return dp[n][k];
    }
};

// x x x x x 6

// 6 x x x x x
// x 6 x x x x
// ...
// x x x x x 6

// dp[6][j] = dp[5][j - 5]
//          + dp[5][j - 4]
//          + ...
//          + dp[5][j - 0]
         
// dp[i][j] = dp[i - 1][j - m]

// dp[i][j]   = dp[i-1][j-0] + dp[i-1][j-1] + dp[i-1][j-2] + ... + dp[i-1][j-(i-2)] dp[i-1][j-(i-1)];
// dp[i][j-1] = dp[i-1][j-1] + dp[i-1][j-2] + dp[i-1][j-3] + ... + dp[i-1][j-(i-1)] dp[i-1][j-i];

// dp[i][j] - dp[i][j-1] = dp[i-1][j] - dp[i-1][j-i]
// dp[i][j] = dp[i-1][j] - dp[i-1][j-i] + dp[i][j-1]

