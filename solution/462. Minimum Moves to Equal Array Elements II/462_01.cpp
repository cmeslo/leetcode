class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(begin(nums), end(nums));
        
        int n = nums.size();
        vector<long> prefix(n);
        prefix[0] = nums[0];
        for (int i = 1; i < n; ++i)
            prefix[i] = prefix[i - 1] + nums[i];
        
        long ans = INT_MAX;
        for (int i = 0; i < n; ++i) {
            long moves = 0;
            long left = (i == 0 ? 0 : prefix[i - 1]);
            long right = (i == n - 1 ? 0 : prefix[n - 1] - prefix[i]);
            moves += (i == 0 ? 0 : (long) i * nums[i]) - left;
            moves += right - (i == n - 1 ? 0 : (long) (n - i - 1) * nums[i]);
            ans = min(ans, moves);
        }
        return ans;
    }
};
