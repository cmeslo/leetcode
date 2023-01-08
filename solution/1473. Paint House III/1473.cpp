class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(target + 1, vector<int>(n + 1, INT_MAX)));
        
        houses.insert(houses.begin(), 0);
        
        for (int k = 0; k <= n; ++k)
            dp[0][0][k] = 0;
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= target; ++j) {
                if (houses[i] == 0) {
                    for (int k = 1; k <= n; ++k) {
                        if (dp[i - 1][j][k] != INT_MAX) {
                            dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k] + cost[i - 1][k - 1]);
                        }
                        
                        for (int pre = 1; pre <= n; ++pre) {
                            if (k == pre || dp[i - 1][j - 1][pre] == INT_MAX) continue;
                            dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - 1][pre] + cost[i - 1][k - 1]);
                        }
                    }
                } else {
                    int k = houses[i];
                    if (dp[i - 1][j][k] != INT_MAX)
                        dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k]);
                    
                    for (int pre = 1; pre <= n; ++pre) {
                        if (k == pre || dp[i - 1][j - 1][pre] == INT_MAX) continue;
                        dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - 1][pre]);
                    }
                }
            }
        }
        
        int res = INT_MAX;
        for (int x : dp[m][target])
            if (x != -1)
                res = min(res, x);
        return res == INT_MAX ? -1 : res;
    }
};



// dp[i][j][k] := the minimum cost of painting houses [0:i] in such a way that there are exactly j neighborhoods, which houses[i] paint with color k

// dp[m][n]

// if (houses[i] == 0)
//     dp[i][j][k] = dp[i-1][j][k] + cost[i][k] if houses[i] same color as houses[i - 1]
//                 = dp[i-1][j-1][pre_color] + cost[i][k] for pre_color in color range[1:n]
// else
//     dp[i][j][k] = dp[i-1][j][k] if houses[i] same color as houses[i - 1]
//                 = dp[i-1][j-1][pre_color] for pre_color in color range[1:n] without k
