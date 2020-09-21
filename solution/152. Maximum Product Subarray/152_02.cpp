class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int minP = nums[0], maxP = nums[0];
        int ans = nums[0];
        
        for (int i = 1; i < nums.size(); ++i) {
            int mx = maxP, mi = minP;
            maxP = max(nums[i], max(nums[i] * mx, nums[i] * mi));
            minP = min(nums[i], min(nums[i] * mx, nums[i] * mi));
            ans = max(ans, maxP);
        }
        
        return ans;
    }
};
