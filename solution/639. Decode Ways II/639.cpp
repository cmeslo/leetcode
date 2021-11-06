class Solution {
public:
    int numDecodings(string s) {
        const int M = 1e9 + 7;
        int n = s.size();
        s.insert(s.begin(), '#');
        
        vector<long> dp(n + 1);
        dp[0] = 1;
        if (s[1] == '*')
            dp[1] = 9;
        else
            dp[1] = s[1] == '0' ? 0 : 1;
        
        for (int i = 2; i <= n; ++i) {
            if (s[i] == '*') {
                dp[i] = dp[i-1] * 9;
                if (s[i - 1] == '1')
                    dp[i] += dp[i-2] * 9;
                else if (s[i - 1] == '2')
                    dp[i] += dp[i-2] * 6;
                else if (s[i - 1] == '*')
                    dp[i] += dp[i-2] * 15;
            } else {
                if (s[i] != '0')
                    dp[i] = dp[i-1];
                if (s[i-1] == '*')
                    dp[i] += dp[i-2] * (s[i] <= '6' ? 2 : 1);
                else if ((s[i-1] == '1' && s[i] <= '9') || (s[i-1] == '2' && s[i] <= '6'))
                    dp[i] += dp[i-2];
            }
            dp[i] %= M;
        }
        return dp[n];
    }
};
