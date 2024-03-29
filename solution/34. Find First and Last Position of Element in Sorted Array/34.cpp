class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = lower_bound(begin(nums), end(nums), target) - begin(nums);
        if (first == nums.size() || nums[first] != target)
            return {-1, -1};
        int last = upper_bound(begin(nums), end(nums), target) - begin(nums);
        return {first, last - 1};
    }
};
