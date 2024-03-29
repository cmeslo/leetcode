class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<int> presum(n);
        presum[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            presum[i] = presum[i - 1] + nums[i];
        }
        
        vector<vector<int>> dp(n, vector<int>(m + 1, INT_MAX));
        for (int i = 0; i < n; ++i)
            dp[i][1] = presum[i];
        
        for (int i = 0; i < n; ++i) {
            for (int k = 2; k <= m; ++k) {
                for (int j = 0; j < i; ++j) {
                    dp[i][k] = min(dp[i][k], max(dp[j][k - 1], presum[i] - presum[j]));
                }
            }
        }
        return dp[n - 1][m];
    }
};


// x x x | x x x x | x x x
//     j         i
    
// dp[i][2] = min(dp[i][2], max(dp[j][1], presum(j:i]))
