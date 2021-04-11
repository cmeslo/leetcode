class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> dp(n);
        for (int i = 0; i < n; ++i)
            dp[i] = s[i] == c ? 0 : n;
        for (int i = 1; i < n; ++i)
            dp[i] = min(dp[i], dp[i - 1] + 1);
        for (int i = n - 2; i >= 0; --i)
            dp[i] = min(dp[i], dp[i + 1] + 1);
        return dp;
    }
};
