class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> res;
        dfs(nums, 0, res);
        return vector<vector<int>> (res.begin(), res.end());
    }
    
    void dfs(vector<int>& nums, int start, set<vector<int>>& res) {
        if (start >= nums.size()) {
            res.insert(nums);
            return;
        }
        
        for (int i = start; i < nums.size(); ++i) {
            if (i != start && nums[start] == nums[i]) continue;
            swap(nums[start], nums[i]);
            dfs(nums, start + 1, res);
            swap(nums[start], nums[i]);
        }
    }
};
