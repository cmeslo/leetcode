class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> out;
        dfs(k, n, out, 1, res);
        return res;
    }
    
    void dfs(int k, int n, vector<int> &out,  int start, vector<vector<int>> &res) {
        if (k == 0) {
            if (n == 0) res.push_back(out);
            return;
        }
        
        for (int i = start; i <= 9; ++i) {
            if (i > n) continue;
            out.push_back(i);
            dfs(k - 1, n - i, out, i + 1, res);
            out.pop_back();
        }
    }
};
