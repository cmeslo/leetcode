class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        const int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] < i + 1)
                return -1;
            if (i + 1 == n || nums[i + 1] < i + 1)
                return i + 1;
        }
        return -1;
    }
};
