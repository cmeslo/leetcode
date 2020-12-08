class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        vector<bool> used(nums.size());
        sort(begin(nums), end(nums));
        dfs(nums, used, cur, ans);
        return ans;
    }
    
private:
    void dfs(vector<int>& nums, vector<bool>& used, vector<int>& cur, vector<vector<int>>& ans) {
        if (cur.size() == nums.size()) {
            ans.push_back(cur);
            return;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) continue;
            if (i > 0 && nums[i - 1] == nums[i] && used[i - 1] == false) continue;
            used[i] = true;
            cur.push_back(nums[i]);
            dfs(nums, used, cur, ans);
            cur.pop_back();
            used[i] = false;
        }
    }
};
