class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int ans = n + 1;
        for (int i = 0, j = 0; j < n; ++j) {
            sum += nums[j];
            while (sum >= target) {
                ans = min(ans, j - i + 1);
                sum -= nums[i++];
            }
        }
        return ans == n + 1 ? 0 : ans;
    }
};
