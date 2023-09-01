class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int n = words[0].size(), len = target.size();
        
        vector<vector<int>> W(n + 1, vector<int>(26));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < words.size(); ++j) {
                W[i + 1][words[j][i] - 'a']++;
            }
        }
        
        using ll = long long;
        const int M = 1e9 + 7;
        vector<vector<ll>> dp(len + 1, vector<ll>(n + 1));
        for (int j = 1; j <= n; ++j) {
            dp[1][j] = (dp[1][j-1] + W[j][target[0] - 'a']) % M;
        }
        for (int i = 2; i <= len; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = (dp[i][j-1] + W[j][target[i-1] - 'a'] * dp[i-1][j-1]) % M;
            }
        }
        return dp[len][n];
    }
};

// "a c c a"
// "b b b b"
// "c a c a"
//    a b a

// dp[i][j] := 用 words[*][0:j] 組成 target[0:i] 有多少種方式

// dp[1][1] = 1
// dp[1][2] = dp[1][1] + 1 = 2

// dp[2][1] = 0
// dp[2][2] = dp[1][1] = 1
// dp[2][3] = dp[2][2] + W[3][b] * dp[1][2] = 1 + 2 = 3

// dp[3][4] = W[4][a] * dp[2][3] = 2 * 3 = 6

// dp[i][j] = dp[i][j-1] + W[i][target[i] - 'a'] * dp[i-1][j-1]
