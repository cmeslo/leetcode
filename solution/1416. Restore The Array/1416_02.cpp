class Solution {
public:
    int numberOfArrays(string s, int k) {
        const int M = 1e9 + 7;
        int maxLen = to_string(k).size();
        int n = s.length();
        s = '#' + s;
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            long num = 0;
            for (int j = i; j >= 1 && num <= k && i - j + 1 <= maxLen; --j) {
                if (s[j] != '0') {
                    num = stol(s.substr(j, i - j + 1));
                    if (num <= k)
                        dp[i] = (dp[i] + dp[j - 1]) % M;
                }
            }
        }
        return dp[n];
    }
};


// 1 3 1 7
// dp[i] := s[:i] 可以組成的數字組合

// dp[i] += dp[j-1] if s[j:i] is valid

// s[j:i] is valid if s[j:i] <= k and no leading zero
