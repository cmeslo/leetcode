class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, res = INT_MAX;
        for (int j = 0; j < nums.size(); ++j) {
            target -= nums[j];
            while (target <= 0) {
                res = min(res, j - i + 1);
                target += nums[i++];
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};
