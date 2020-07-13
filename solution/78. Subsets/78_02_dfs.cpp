class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(nums, 0, cur, res);
        return res;
    }
    
    void dfs(vector<int>& nums, int index, vector<int>& cur, vector<vector<int>>& res) {
        res.push_back(cur);
        for (int i = index; i < nums.size(); ++i) {
            cur.push_back(nums[i]);
            dfs(nums, i + 1, cur, res);
            cur.pop_back();
        }
    }
};
