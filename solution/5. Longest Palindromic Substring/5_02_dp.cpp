class Solution {
public:
    string longestPalindrome(string s) {
        int dp[s.size()][s.size()] = {{0}}, left = 0, right = 0, len = 0;

        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                dp[j][i] = 0;
                if (s[j] == s[i]) {
                    if (i - j < 2 || dp[j + 1][i - 1]) dp[j][i] = 1;
                }
                // dp[j][i] = (s[i] == s[j] && (i - j < 2 || dp[j + 1][i - 1]));
                
                if (dp[j][i] && i - j + 1 > len) {
                    len = i - j + 1;
                    left = j;
                    right = i;
                }
            }
            dp[i][i] = 1;
        }
        return s.substr(left, right - left + 1);
    }
};
