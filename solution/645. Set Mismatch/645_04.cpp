class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        for (int& x : nums)
            while (nums[x - 1] != x)
                swap(x, nums[x - 1]);
        
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] != i + 1)
                return {nums[i], i + 1};
        
        return {};
    }
};
