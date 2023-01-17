class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        for (int i = n - 1; i > 0; --i) {
            auto temp = nums;
            for (int j = 0; j < i; ++j) {
                temp[j] = (nums[j] + nums[j + 1]) % 10;
            }
            nums = temp;
        }
        return nums[0];
    }
};
