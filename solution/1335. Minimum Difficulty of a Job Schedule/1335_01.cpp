class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int D) {
        const int n = jobDifficulty.size();
        if (n < D) return -1;
        
        vector<vector<int>> dp(n + 1, vector<int>(D + 1, INT_MAX / 2));
        dp[0][0] = 0;
        
        for (int i = 1; i <= n; ++i) {
            for (int d = 1; d <= min(D, i); ++d) {
                int mx = 0;
                for (int j = i; j >= d; --j) {
                    mx = max(mx, jobDifficulty[j - 1]);
                    dp[i][d] = min(dp[i][d], dp[j-1][d-1] + mx);
                }
            }
        }
        return dp[n][D];
    }
};


// dp[i][d] := 在第 d 日完成 i 個 job 的最少 difficulty

// dp[n][d]


// x x | x x x | x
//       j   i

// dp[i][d] = dp[j-1][d-1] + max(j:i) for f in range(1:j-1)
