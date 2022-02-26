class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < n; ++i)
            pos[nums[i]].push_back(i);
        
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long val = nums[j] * 2L - nums[i];
                if (val < INT_MIN || val > INT_MAX) continue;
                for (int k : pos[val]) {
                    if (k < j)
                        dp[j][i] += dp[k][j] + 1;
                }
            }
        }
        
        int res = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j)
                res += dp[j][i];
        return res;
    }
};

// nums[k], nums[j], nums[i]
// nums[k] - nums[j] = nums[j] - nums[i]
// nums[k] = nums[j] + nums[j] - nums[i]
