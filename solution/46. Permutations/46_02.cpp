class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        dfs(nums, 0, res);
        return res;
    }
    
    void dfs(vector<int>& nums, int start, vector<vector<int>>& res) {
        if (start >= nums.size()) {
            res.push_back(nums);
            return;
        }
        
        for (int i = start; i < nums.size(); ++i) {
            swap(nums[start], nums[i]);
            dfs(nums, start + 1, res);
            swap(nums[start], nums[i]);
        }
    }
};
