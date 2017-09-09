class Solution {
public:
    int findLHS(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int maxLen = 0;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); ++i) {
            int len = 1;
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[j] - nums[i] <= 1)
                    ++len;
                else 
                    break;
                
                if (len > maxLen && nums[i] != nums[j]) maxLen = len;
            }
        }
        return maxLen;
    }
};
