class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for (int i = 0; i < n; ++i)
            dp[i][i] = 1;
        
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j])
                    dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + 2);
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
            }
        }
        return dp[0][n - 1];
    }
};


// b b b a b

// b . . . b
//   b . . b
//     b . b

// b ... a ... [b]
// b ... [b]

// dp[i][j] := Longest Palindromic Subsequence in s[i:j]

// dp[i][j] = dp[i + 1][j - 1] + 2 if (s[i] == s[j])

// dp[i][i] = 1

// dp[0][4] = dp[1][3] + 2

// dp[i][j] = max(dp[i][j-1], dp[i+1][j])
