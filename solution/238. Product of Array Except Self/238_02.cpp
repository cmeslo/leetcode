class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int n = nums.size();
        vector<int> prefix(n + 1), suffix(n + 1);
        prefix[0] = nums[0];
        suffix[n - 1] = nums[n - 1];
        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] * nums[i];
            suffix[n - i - 1] = suffix[n - i] * nums[n - i - 1];
        }

        vector<int> res(n);
        res[0] = suffix[1];
        res[n - 1] = prefix[n - 2];
        for (int i = 1; i < n - 1; ++i)
            res[i] = prefix[i - 1] * suffix[i + 1];
        return res;
    }
};
