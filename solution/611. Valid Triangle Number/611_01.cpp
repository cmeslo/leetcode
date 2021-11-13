class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                auto it = lower_bound(nums.begin() + j + 1, nums.end(), nums[i] + nums[j]);
                int k = it - nums.begin() - 1;
                if (nums[i] + nums[j] > nums[k])
                    ans += k - j;
            }
        }
        
        return ans;
    }
};
