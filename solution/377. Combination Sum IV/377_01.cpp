class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target + 1);
        dp[0] = 1;
        for (int sum = 1; sum <= target; ++sum) {
            for (int x : nums) {
                if (sum < x) continue;
                dp[sum] += dp[sum - x];
            }
        }
        return dp[target];
    }
};
