class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, false);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                if (dp[i - j * j] == false) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};

// 1 2 3 4  5  6
// 1 4 9 16 25 36
    
// dp[1] = true    x
// dp[2] = false   {1} dp[2 - 1] == false
// dp[3] = true    {1} dp[3 - 1] == false
// dp[4] = true    x
// dp[5] = false   {1, 4} (dp[5 - 1] == false || dp[5 - 4] == false)
// dp[6] = true    {1, 4} (dp[6 - 1] == false || dp[6 - 4] == false)
// dp[7] = false   {1, 4} (dp[7 - 1] == false || dp[7 - 4] == false)
// dp[8] = true    {1, 4} (dp[8 - 1] == false || dp[8 - 4] == false)
// dp[9] = true    x
// dp[10]= false   {1, 4, 9} (dp[10 - 1] == false || dp[10 - 4] == false || dp[10 - 9] == false)
