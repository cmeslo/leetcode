class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(2, 0);
        bool found = false;
        
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
            if (i > 0 && nums[i - 1] == nums[i]) res[0] = nums[i];
            if (!found && nums[i] != i + 1) {
                res[1] = i + 1;
                if (nums[i] > i + 1) found = true;
            }
        }
        return res;
    }
};
