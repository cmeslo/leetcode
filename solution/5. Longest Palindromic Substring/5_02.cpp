class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0, len = 0;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for (int l = 1; l <= n; ++l) {
            for (int i = 1; i + l - 1 <= n; ++i) {
                int j = i + l - 1;
                
                if (l == 1)
                    dp[i][i] = 1;
                else if (l == 2)
                    dp[i][j] = s[i - 1] == s[j - 1] ? 2 : 0;
                else if (s[i - 1] == s[j - 1] && dp[i + 1][j - 1])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                
                if (dp[i][j] > len) {
                    len = dp[i][j];
                    start = i - 1;
                }
            }
        }
        return s.substr(start, len);
    }
};

// x x x x x x
//     i
//     j

// x x x x x x
//   i j

// x x x x x x x x
//   i       j

// dp[i][j] = dp[i + 1][j - 1] + 2 if s[i] == s[j]
