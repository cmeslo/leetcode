class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(begin(nums), end(nums));
        backtrack(nums, 0, ans);
        return ans;
    }
    
private:
    void backtrack(vector<int>& nums, int len, vector<vector<int>>& ans) {
        if (len == nums.size()) {
            ans.push_back(nums);
            return;
        }
        
        backtrack(nums, len + 1, ans);
        for (int i = 0; i < len; ++i) {
            if (nums[i] == nums[len])
                break;
            swap(nums[i], nums[len]);
            backtrack(nums, len + 1, ans);
            swap(nums[i], nums[len]);
        }
    }
};
