class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int res = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] >= nums[i]) {
                res += nums[i - 1] + 1 - nums[i];
                nums[i] = nums[i - 1] + 1;
            }
        }
        return res;
    }
};

// 1 1 2 2 3 7
// 1 2 3 

// 1 2 3 4 5 7
