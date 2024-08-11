class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        const int n = nums.size();
        vector<int> res;
        int i = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int j = i - 1;
        while (j >= 0 || i < n) {
            if (i == n) {
                res.push_back(nums[j] * nums[j]);
                j--;
            } else if (j < 0) {
                res.push_back(nums[i] * nums[i]);
                i++;
            } else {
                if (nums[i] * nums[i] < nums[j] * nums[j]) {
                    res.push_back(nums[i] * nums[i]);
                    i++;
                } else {
                    res.push_back(nums[j] * nums[j]);
                    j--;
                }
            }
        }
        return res;
    }
};
