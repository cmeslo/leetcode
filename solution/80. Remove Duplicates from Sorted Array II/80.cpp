class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int j = 0; j < nums.size(); ++j) {
            if (j > 1 && nums[i - 2] == nums[j]) continue;
            nums[i++] = nums[j];
        }
        
        return i;
    }
};
