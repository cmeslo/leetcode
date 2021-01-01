class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> max_left(n), max_right(n);
        
        max_left[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            max_left[i] = i % k ? max(max_left[i - 1], nums[i]) : nums[i];
        }
        
        max_right[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            max_right[i] = i % k ? max(nums[i], max_right[i + 1]) : nums[i];
        }
        
        vector<int> ans(n - k + 1);
        for (int i = 0; i + k - 1 < n; ++i) {
            ans[i] = max(max_left[i + k - 1], max_right[i]);
        }
        
        return ans;
    }
};
