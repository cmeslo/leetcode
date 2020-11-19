class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        
        vector<string> ans;
        for (int l = 0; l < n; ++l) {
            int r = l;
            while (r + 1 < n && nums[r] + 1 == nums[r + 1])
                ++r;
            ans.push_back(l == r ? to_string(nums[l]) : to_string(nums[l]) + "->" + to_string(nums[r]));
            l = r;
        }
        
        return ans;
    }
};
