class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int j = 0;
        for (int i = 0; i < n && i <= j && j < n - 1; ++i) {
            j = max(j, i + nums[i]);
        }
        return j >= n - 1;
    }
};
