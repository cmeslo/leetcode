class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int n = target.size(), M = 1e9 + 7;
        vector<long> dp(n + 1);
        dp[0] = 1;
        for (int i = 0; i < words[0].size(); ++i) {
            vector<int> count(26);
            for (auto& w : words)
                count[w[i] - 'a']++;
            
            for (int j = n - 1; j >= 0; --j) {
                dp[j + 1] += dp[j] * count[target[j] - 'a'] % M;
            }
        }
        return dp[n] % M;
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
