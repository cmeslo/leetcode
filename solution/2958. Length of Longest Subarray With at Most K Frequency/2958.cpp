class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int res = 0;
        unordered_map<int, int> f;
        for (int i = 0, j = 0; j < nums.size(); ++j) {
            ++f[nums[j]];
            while (f[nums[j]] > k) {
                if (--f[nums[i]] == 0)
                    f.erase(nums[i]);
                ++i;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};
