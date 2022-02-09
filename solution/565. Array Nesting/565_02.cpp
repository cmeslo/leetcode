class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int group_size = 1;
            while (nums[i] != i) {
                swap(nums[i], nums[nums[i]]);
                ++group_size;
            }
            res = max(res, group_size);
        }
        return res;
    }
};
