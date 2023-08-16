class Solution {
public:
    int maxSatisfaction(vector<int>& s) {
        int n = s.size();
        sort(s.begin(), s.end());
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MIN));
        
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i][1] = max(dp[i - 1][1], s[i - 1]);
            res = max(res, dp[i][1]);
            for (int seq = 2; seq <= i; ++seq) {
                dp[i][seq] = dp[i - 1][seq - 1] + seq * s[i - 1];
                res = max(res, dp[i][seq]);
            }
        }
        return res;
    }
};


// x x x x x x

// dp[i][j] = 前 i 種餸, 組成 j 道菜, 獲得的最高分數

// dp[i][1] = max(dp[i-1][1], s[i])
// dp[i][2] = dp[i-1][1] + 2*s[i]
