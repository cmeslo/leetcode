class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();
        nums.insert(nums.begin(), 0);
        
        int res = INT_MIN;
        vector<vector<int>> dp(m + 1, vector<int>(m + 1, INT_MIN));
        dp[0][0] = 0;
        for (int len = 1; len <= m; ++len) {
            for (int i = 0; i <= len; ++i) {
                int j = len - i;
                if (i >= 1)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j] + nums[i] * multipliers[i + j - 1]);
                if (j >= 1)
                    dp[i][j] = max(dp[i][j], dp[i][j - 1] + nums[n - j + 1] * multipliers[i + j - 1]);
                
                if (len == m)
                    res = max(res, dp[i][j]);
            }
        }
        
        return res;
    }
};



// dp[i][j] = 從頭取 i 個, 從尾取 j 個

// x x [x] x x x x [x] x x x
//      i           j

// dp[i][j] = max(dp[i - 1][j] + nums[i] * multipliers[i + j],
//                dp[i][j - 1] + nums[n - j + 1] * multipliers[i + j])
