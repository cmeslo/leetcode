class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int dp0 = 0, dp1 = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '0')
                dp1 = min(dp0, dp1) + 1;
            else {
                dp1 = min(dp0, dp1);
                dp0 = dp0 + 1;
            }
        }
        return min(dp0, dp1);
    }
};

// x x x x x x [x]

// if (s[i] == '0')
//     dp[i][0] = dp[i-1][0]
//     dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + 1
// if (s[i] == '1')
//     dp[i][0] = dp[i-1][0] + 1
//     dp[i][1] = min(dp[i-1][0], dp[i-1][1])
