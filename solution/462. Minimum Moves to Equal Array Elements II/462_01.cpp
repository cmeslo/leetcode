class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<int> presum(n + 1);
        for (int i = 1; i <= n; ++i)
            presum[i] = presum[i - 1] + nums[i - 1];
        
        long ans = INT_MAX;
        for (int i = 1; i <= n; ++i) {
            long left = 1L * nums[i - 1] * (i - 1) - presum[i - 1];
            long right = presum[n] - presum[i] - 1L * (n - i) * nums[i - 1];
            ans = min(ans, left + right);
        }
        return ans;
    }
};
