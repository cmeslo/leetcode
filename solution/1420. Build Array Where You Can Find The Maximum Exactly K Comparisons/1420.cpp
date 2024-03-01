class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        const int M = 1e9 + 7;
        int K = k;
        long dp[n][m + 1][K + 1];
        memset(dp, 0, sizeof(dp));

        for (int j = 1; j <= m; ++j)
            dp[0][j][1] = 1;

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= m; ++j) {
                for (int k = 1; k <= K; ++k) {
                    for (int t = 1; t < j; ++t) {
                        dp[i][j][k] = (dp[i][j][k] + dp[i-1][t][k-1]) % M;
                    }
                    dp[i][j][k] = (dp[i][j][k] + dp[i-1][j][k] * j) % M;
                }
            }
        }

        long res = 0;
        for (int j = 1; j <= m; ++j)
            res = (res + dp[n - 1][j][k]) % M;
        return res;
    }
};

// dp[i][j][k] := the number of ways to build the arr[1:i] and max(arr[1:i]) = j and search cost is k

// if arr[i] is the largest among arr[1:i]  => arr[i] = j
// dp[i][j][k] += sum(dp[i-1][1...j-1][k-1])

// if arr[i] is not the largest among arr[1:i]  => arr[i] <= j
// dp[i][j][k] += dp[i-1][j][k] * j
