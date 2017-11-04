class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> out, used(nums.size(), 0);
        std::sort(nums.begin(), nums.end());
        dfs(nums, used, out, res);
        return res;
    }
    
    void dfs(vector<int>& nums, vector<int>& used, vector<int>& out, vector<vector<int>>& res) {
        if (out.size() == nums.size()) {
            res.push_back(out);
            return;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i - 1] == nums[i] && used[i - 1]) continue;
            if (!used[i]) {
                out.push_back(nums[i]);
                used[i] = 1;
                dfs(nums, used, out, res);
                used[i] = 0;
                out.pop_back();
            }
        }
    }
};
