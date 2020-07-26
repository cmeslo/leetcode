class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        std::sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, cur, ans);
        return vector<vector<int>>(ans.begin(), ans.end());
    }

private:
    void dfs(vector<int>& candidates, int target, int s, vector<int>& cur, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(cur);
            return;
        }
        
        for (int i = s; i < candidates.size(); i++) {
            if (candidates[i] > target) return;
            if (i > s && candidates[i] == candidates[i-1]) continue;
            cur.push_back(candidates[i]);
            dfs(candidates, target-candidates[i], i+1, cur, ans);
            cur.pop_back();
        }
    }
};
