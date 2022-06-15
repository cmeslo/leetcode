class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int dp_max = nums[0], dp_min = nums[0];
        int res = nums[0];
        
        for (int i = 1; i < nums.size(); ++i) {
            int mx = dp_max, mn = dp_min;
            if (nums[i] > 0) {
                dp_max = max(mx * nums[i], nums[i]);
                dp_min = min(mn * nums[i], nums[i]);
            } else if (nums[i] < 0) {
                dp_max = max(mn * nums[i], nums[i]);
                dp_min = min(mx * nums[i], nums[i]);
            } else {
                dp_max = dp_min = 0;
            }
            res = max(res, dp_max);
        }
        return res;
    }
};
