class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        return res;
    }
    
private:
    vector<vector<int>> res;
    vector<int> cur;
    
    void dfs(vector<int>& A, int target, int start) {
        if (target < 0) return;
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        
        for (int i = start; i < A.size(); ++i) {
            if (start < i && A[i - 1] == A[i]) continue;
            cur.push_back(A[i]);
            dfs(A, target - A[i], i + 1);
            cur.pop_back();
        }
    }
};
