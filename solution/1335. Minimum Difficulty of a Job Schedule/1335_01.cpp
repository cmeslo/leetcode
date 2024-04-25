class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int D) {
        const int n = jobDifficulty.size();
        if (n < D) return -1;
        
        jobDifficulty.insert(jobDifficulty.begin(), 0);
        vector<vector<int>> mx(n + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                for (int k = i; k <= j; ++k)
                    mx[i][j] = max(mx[i][j], jobDifficulty[k]);
            }
        }
        
        vector<vector<int>> dp(n + 1, vector<int>(D + 1, INT_MAX));
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int d = 1; d <= D; ++d) {
                for (int j = 1; j <= i; ++j) {
                    if (dp[j-1][d-1] == INT_MAX) continue;
                    dp[i][d] = min(dp[i][d], dp[j-1][d-1] + mx[j][i]);
                }
            }
        }
        return dp[n][D] == INT_MAX ? -1 : dp[n][D];
    }
};


// dp[i][d] := 在第 d 日完成 i 個 job 的最少 difficulty

// dp[n][d]


// x x | x x x | x
//       j   i

// dp[i][d] = dp[j-1][d-1] + max(j:i) for f in range(1:j-1)
