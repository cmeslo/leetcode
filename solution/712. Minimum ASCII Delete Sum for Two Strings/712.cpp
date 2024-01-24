class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        s1.insert(s1.begin(), '#');
        s2.insert(s2.begin(), '#');
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX / 2));
        dp[0][0] = 0;
        for (int i = 1; i <= m; ++i)
            dp[i][0] = dp[i-1][0] + s1[i];
        for (int j = 1; j <= n; ++j)
            dp[0][j] = dp[0][j-1] + s2[j];
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s1[i] == s2[j]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min(dp[i-1][j] + s1[i],
                                   dp[i][j-1] + s2[j]);
                }
            }
        }
        return dp[m][n];
    }
};


// x x x
//     i
// x x x x
//       j

// dp[i][j] = dp[i-1][j-1] if s1[i] == s2[j]
//            min(dp[i-1][j] + ascii(s1[i]),
//                dp[i][j-1] + ascii(s2[j])) if s1[i] != s2[j]

// dp[0][1]
