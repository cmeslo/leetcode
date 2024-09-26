class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        const int n = nums.size();
        for (int x : nums) {
            while (x > 0 && x <= n && nums[x - 1] != x)
                swap(nums[x - 1], x);
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1)
                return i + 1;
        }
        return n + 1;
    }
};
