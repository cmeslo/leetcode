class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        const int n = nums.size();
        vector<int> left(n), right(n);
        for (int i = 1; i < n; ++i) {
            if (nums[i - 1] == 1)
                left[i] = left[i - 1] + 1;
        }
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i + 1] == 1)
                right[i] = right[i + 1] + 1;
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res = max(res, left[i] + right[i]);
        }
        return res;
    }
};
