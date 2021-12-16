class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        piles.insert(piles.begin(), 0);
        
        vector<int> presum(n + 1);
        for (int i = 1; i <= n; ++i)
            presum[i] = presum[i - 1] + piles[i];
        
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; ++i)
            dp[i][i] = piles[i];
        
        for (int len = 2; len <= n; ++len) {
            for (int i = 1; i + len - 1 <= n; ++i) {
                int j = i + len - 1;
                dp[i][j] = max(presum[j] - presum[i - 1] - dp[i + 1][j],
                               presum[j] - presum[i - 1] - dp[i][j - 1]);
            }
        }
        
        return dp[1][n] > presum[n] - dp[1][n];
    }
};
