class Solution {
public:
    int longestIdealString(string s, int k) {
        const int n = s.size();
        vector<vector<int>> dp(n, vector<int>(26));
        int res = dp[0][s[0] - 'a'] = 1;
        for (int i = 1; i < n; ++i) {
            int c = s[i] - 'a';
            for (int j = 0; j < 26; ++j)
                dp[i][j] = dp[i - 1][j];
            for (int j = max(0, c - k); j <= min(25, c + k); ++j)
                dp[i][c] = max(dp[i][c], dp[i - 1][j] + 1);
            res = max(res, dp[i][c]);
        }
        return res;
    }
};


// x x x x c

// dp[i][c] = dp[i - 1][c-k : c+k] + 1
