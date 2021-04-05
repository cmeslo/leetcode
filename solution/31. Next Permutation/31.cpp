class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 1;;
        
        for (i = n - 1; i > 0; --i) {
            if (nums[i - 1] < nums[i]) {
                for (int j = n - 1; j >= i; --j) {
                    if (nums[i - 1] < nums[j]) {
                        swap(nums[i - 1], nums[j]);
                        break;
                    }
                }
                break;
            }
        }
        
        reverse(begin(nums) + i, end(nums));
    }
};
