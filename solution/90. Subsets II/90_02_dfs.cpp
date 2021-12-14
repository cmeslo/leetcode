class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> path;
        dfs(nums, 0, path, ans);
        return ans;
    }
    
private:
    void dfs(vector<int>& nums, int s, vector<int>& path, vector<vector<int>>& ans) {
        ans.push_back(path);
        for (int i = s; i < nums.size(); ++i) {
            if (i > s && nums[i - 1] == nums[i]) continue;
            path.push_back(nums[i]);
            dfs(nums, i + 1, path, ans);
            path.pop_back();
        }
    }
};
