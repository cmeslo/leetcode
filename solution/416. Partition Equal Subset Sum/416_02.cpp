class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(begin(nums), end(nums), 0);
        if (sum & 1) return false;
        
        int target = sum >> 1;
        vector<bool> dp(target + 1, false);
        
        dp[0] = true;
        if (nums[0] <= target)
            dp[nums[0]] = true;
        
        for (int i = 1; i < n; ++i) {
            for (int j = target; j >= 0 && nums[i] <= j; --j) {
                dp[j] = dp[j] || dp[j - nums[i]];
            }
            if (dp[target]) return true;
        }
        
        return dp[target];
    }
};
