class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const int M = 1e9 + 7;
        vector<vector<long>> dp(n + 1, vector<long>(target + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int x = 1; x <= target; ++x) {
                for (int j = 1; j <= k && x >= j; ++j) {
                    dp[i][x] = (dp[i][x] + dp[i - 1][x - j]) % M;
                }
            }
        }
        return dp[n][target];
    }
};

// dp[n][target]

// dp[i][x] = dp[i][x - j] for j = 1 to k
