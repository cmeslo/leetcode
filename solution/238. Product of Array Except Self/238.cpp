class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        int product = 1;
        for (int i = 0; i < n; ++i) {
            res[i] = product;
            product *= nums[i];
        }
        product = 1;
        for (int i = n - 1; i >= 0; --i) {
            res[i] *= product;
            product *= nums[i];
        }
        return res;
    }
};
