class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        
        int maxIdx = 0;
        
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[maxIdx]) maxIdx = i;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (i != maxIdx && nums[maxIdx] < 2 * nums[i]) return -1;
        }
        
        return maxIdx;
    }
};
