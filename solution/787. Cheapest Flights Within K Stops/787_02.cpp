class Solution {
public:
    // Bellman-Ford algorithm
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<int>> dp(K+2, vector<int>(n, 1e9));
        
        dp[0][src] = 0;
        for (int i = 1; i <= K+1; ++i) {
            dp[i][src] = 0;
            for (const vector<int>& f : flights) {
                int from_place = f[0], to_place = f[1], cost = f[2];
                dp[i][to_place] = min(dp[i][to_place], dp[i-1][from_place] + cost);
            }
        }
        return (dp[K+1][dst] >= 1e9) ? -1 : dp[K+1][dst];
    }
};
