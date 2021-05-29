class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int ans = 1;
        int dir = 0;
        
        for (int i = 1; i < nums.size(); ++i) {
            int pre_dir = dir;
            
            if (nums[i - 1] < nums[i])
                dir = 1;
            else if (nums[i - 1] > nums[i])
                dir = -1;
            
            if (pre_dir != dir)
                ++ans;
        }
        
        return ans;
    }
};
