class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();
        int ans = INT_MAX;
        for (int i = start; i < n; ++i) {
            if (nums[i] == target) {
                ans = min(ans, abs(i - start));
                break;
            }
        }
        for (int i = start - 1; i >= 0; --i) {
            if (nums[i] == target) {
                ans = min(ans, abs(i - start));
                break;
            }
        }
        return ans;
    }
};
