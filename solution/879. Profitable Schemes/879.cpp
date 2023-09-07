class Solution {
private:
    int dp[105][105][105];
    const int M = 1e9 + 7;
    
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int m = group.size();
        
        dp[0][0][0] = 1;
        group.insert(group.begin(), 0);
        profit.insert(profit.begin(), 0);
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j <= n; ++j) {
                for (int k = 0; k <= minProfit; ++k) {
                    
                    dp[i+1][j][k] += dp[i][j][k];
                    dp[i+1][j][k] %= M;
                    
                    if (j + group[i+1] <= n) {
                        dp[i+1][j + group[i+1]][min(minProfit, k+profit[i+1])] += dp[i][j][k];
                        dp[i+1][j + group[i+1]][min(minProfit, k+profit[i+1])] %= M;
                    }
                }
            }
        }
        int res = 0;
        for (int j = 0; j <= n; ++j)
            res = (res + dp[m][j][minProfit]) % M;
        return res;
    }
};
