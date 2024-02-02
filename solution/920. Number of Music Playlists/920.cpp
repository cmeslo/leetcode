class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        const int M = 1e9 + 7;
        vector<vector<long>> dp(goal + 1, vector<long>(n + 1));
        dp[1][1] = n;

        for (int i = 2; i <= goal; ++i) {
            for (int j = 1; j <= min(i, n); ++j) {
                if (i > k)
                    dp[i][j] += dp[i - 1][j] * (j - k);
                if (n > j - 1)
                    dp[i][j] += dp[i - 1][j - 1] * (n - j + 1);
                dp[i][j] %= M;
            }
        }

        return dp[goal][n];
    }
};



// x x x x x x x x
//         i
//         j
