class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int i = 0, n = nums.size();;
        int increasing = 1, decreasing = 1;
        for (i = 1; i < n; ++i) {
            if (nums[i - 1] <= nums[i]) {
                increasing++;
            }
            if (nums[i - 1] >= nums[i]) {
                decreasing++;
            }
        }
        return increasing == n || decreasing == n;
    }
};
