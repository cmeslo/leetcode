class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> ans;
        vector<int> cur;
        std::sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, cur, ans);
        return vector<vector<int>>(ans.begin(), ans.end());
    }

private:
    void dfs(vector<int>& candidates, int target, int s, vector<int>& cur, set<vector<int>>& ans) {
        if (target == 0) {
            ans.insert(cur);
            return;
        }
        
        for (int i = s; i < candidates.size(); i++) {
            if (candidates[i] > target) break;
            cur.push_back(candidates[i]);
            dfs(candidates, target-candidates[i], i+1, cur, ans);
            cur.pop_back();
        }
    }
};
