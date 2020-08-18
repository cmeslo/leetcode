class Solution {
public:
    vector<int> getRow(int k) {
        vector<int> ans;
        
        vector<vector<int>> dp(k+1, vector<int>(k+1, 0));
        for (int i = 0; i < k+1; i++) {
            dp[0][i] = 1;
            dp[i][0] = 1;
        }
        
        int limit = k;
        for (int i = 1; i < k; i++) {
            for (int j = 1; j < limit; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
            limit--;
        }
        
 
        int i = k, j = 0;
        while (j <= k)
            ans.push_back(dp[i--][j++]);
        
        return ans;
    }
};
