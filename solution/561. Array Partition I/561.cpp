class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        std::sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < nums.size() - 1; i+=2) {
            res += min(nums[i], nums[i + 1]);
        }
        return res;
    }
};
