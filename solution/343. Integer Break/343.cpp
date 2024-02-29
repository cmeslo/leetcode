class Solution {
public:
    int integerBreak(int n) {
        memset(memo, -1, sizeof(memo));
        return dfs(n);
    }

private:
    int memo[59];

    int dfs(int n) {
        if (n <= 3) return n - 1;
        if (memo[n] != -1) return memo[n];
        int res = 0;
        for (int i = 2; i < n; ++i) {
            res = max(res, i * dfs(n - i));
            res = max(res, i * (n - i));
        }
        return memo[n] = res;
    }
};


// dp[10] = dp[6] + dp[4]
//        = dp[3] + dp[3] + dp[4]

// dp[2] = 1*1 = 1;
// dp[3] = 2*1 = 2;
// dp[4] = 2*2 = 4;
// dp[5] = 3*2 = 6;
// dp[6] = 3*3 = 9;
// dp[7] = 4*3 = 12;
