class Solution {
public:
    bool winnerSquareGame(int n) {
        static vector<int> dp(100001, -1); // -1 = unknow, 0 = lose, 1 = win
        
        if (dp[n] >= 0) return dp[n];
        
        for (int j = 1; j * j <= n; ++j)
            if (!winnerSquareGame(n - j * j))
                return dp[n] = 1;
        
        return dp[n] = 0;
    }
};
