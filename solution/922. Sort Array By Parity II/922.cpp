class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 1;
        while (i < n && j < n) {
            while (i < n && nums[i] % 2 == 0) i += 2; // 找到放錯位的 nums[i]
            while (j < n && nums[j] % 2 == 1) j += 2; // 找到放錯位的 nums[j]
            if (i < n && j < n) // 如果 i 或 j 已經出界，代表沒有放錯位了
                swap(nums[i], nums[j]);
        }
        return nums;
    }
};
