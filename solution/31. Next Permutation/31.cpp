class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return;
        
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                for (int j = n - 1; j >= 0; --j) {
                    if (nums[i] < nums[j]) {
                        std::swap(nums[i], nums[j]);
                        std::reverse(nums.begin() + i + 1, nums.end());
                        return;
                    }
                }   
            }
        }
        std::reverse(nums.begin(), nums.end());
    }
};
