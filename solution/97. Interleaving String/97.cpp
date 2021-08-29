class Solution {
public:
    bool isInterleave(string A, string B, string C) {
        int n = A.size(), m = B.size();
        if (n + m != C.size()) return false;
        
        A.insert(begin(A), '#');
        B.insert(begin(B), '#');
        C.insert(begin(C), '#');
        
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));
        
        dp[0][0] = true;
        for (int i = 1; i <= n; ++i)
            dp[i][0] = dp[i - 1][0] && A[i] == C[i];
        
        for (int j = 1; j <= m; ++j)
            dp[0][j] = dp[0][j - 1] && B[j] == C[j];
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (A[i] == C[i + j] && dp[i - 1][j])
                    dp[i][j] = true;
                else if (B[j] == C[i + j] && dp[i][j - 1])
                    dp[i][j] = true;
            }
        }
        return dp[n][m];
    }
};
