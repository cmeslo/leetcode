class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int max = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            int curr = 1;
            while (nums[i] != i) {
                curr++;
                swap(nums[i], nums[nums[i]]);
            }
            if (curr > max) max = curr;
        }
        
        return max;
    }
};
