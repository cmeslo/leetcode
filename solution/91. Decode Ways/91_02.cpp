class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0 || s[0] == '0') return 0;
        
        int dp2 = 0, dp1 = 1; // dp2: dp[i - 2], dp1: dp[i - 1]
        for (int i = 0; i < n; ++i) {
            int dpi = 0;
            if (!valid(s[i]) && !valid(s[i - 1], s[i])) // invalid, eg: 00
                return 0;
            if (valid(s[i]))
                dpi = dp1;
            if (i - 1 >= 0 && valid(s[i - 1], s[i]))
                dpi += dp2;
            dp2 = dp1;
            dp1 = dpi;
        }
        return dp1;
    }
    
private:
    bool valid(const char c) {
        return c != '0';
    }
    bool valid(const char c1, const char c2) {
        int num = (c1 - '0') * 10 + (c2 - '0');
        return 10 <= num && num <= 26;
    }
};
