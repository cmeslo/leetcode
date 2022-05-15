class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int res = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            res = max(1, res - nums[i]);
        }
        return res;
    }
};
