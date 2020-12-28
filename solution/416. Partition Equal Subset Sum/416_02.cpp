class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(begin(nums), end(nums), 0);
        if (sum & 1) return false;
        
        int target = sum / 2;
        vector<bool> dp(target + 1);
        
        dp[0] = true; // base case
        for (int num : nums) {
            for (int i = target; i >= num; --i) {
                dp[i] = dp[i] || dp[i - num];
            }
        }
        
        return dp[target];
    }
};
