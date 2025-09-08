class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX / 2));
        for (int i = 0; i < n; ++i)
            dp[i][i] = 1;
        
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                dp[i][j] = 1 + dp[i + 1][j];
                for (int k = i + 1; k < j; ++k) {
                    if (s[i] == s[k])
                        dp[i][j] = min(dp[i][j], dp[i][k - 1] + dp[k + 1][j]);
                }
                if (s[i] == s[j])
                    dp[i][j] = min(dp[i][j], dp[i][j - 1]);
            }
        }
        // for (int len = 2; len <= n; ++len) {
        //     for (int i = 0; i + len - 1 < n; ++i) {
        //         int j = i + len - 1;
        //         dp[i][j] = 1 + dp[i + 1][j];
        //         for (int k = i + 1; k < j; ++k) {
        //             if (s[i] == s[k])
        //                 dp[i][j] = min(dp[i][j], dp[i][k - 1] + dp[k + 1][j]);
        //         }
        //         if (s[i] == s[j])
        //             dp[i][j] = min(dp[i][j], dp[i][j - 1]);
        //     }
        // }
        return dp[0][n - 1];
    }
};


// aaa
//  b

// a x x x a x x a x x x 
// i       k'    k     j

// dp[i][j] = min{dp[i][k-1] + dp[k+1][j]}

// [a x x x x x] a
