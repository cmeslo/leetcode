class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int res = 0;
        for (int i = 0, j = 1; j < nums.size() - 1; ++j) {
            if ((nums[i] < nums[j] && nums[j] > nums[j + 1]) ||
                (nums[i] > nums[j] && nums[j] < nums[j + 1])) {
                   ++res;
                   i = j;
               }
        }
        return res;
    }
};
