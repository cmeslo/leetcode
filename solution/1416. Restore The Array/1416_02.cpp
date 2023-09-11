class Solution {
public:
    int numberOfArrays(string s, int k) {
        const int M = 1e9 + 7;
        int n = s.size();
        vector<int> dp(n + 1);
        dp[n] = 1;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '0') continue;
            long x = 0;
            for (int j = i; j < n; ++j) {
                x = x * 10 + s[j] - '0';
                if (x > k) break;
                dp[i] = (dp[i] + dp[j + 1]) % M;
            }
        }
        return dp[0];
    }
};
