class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, m = 0, r = nums.size() - 1;
        while (m <= r) {
            if (nums[m] == 0)
                swap(nums[l++], nums[m++]);
            else if (nums[m] == 2)
                swap(nums[r--], nums[m]);
            else
                ++m;
        }
    }
};
