class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> visited(nums.size(), 0), out;
        dfs(nums, visited, out, res);
        return res;
    }
    
    void dfs(vector<int>& nums, vector<int>& visited, vector<int>& out, vector<vector<int>>& res) {
        if (out.size() == nums.size()) {
            res.push_back(out);
            return;
        }
        
        for (int i = 0 ; i < nums.size(); ++i) {
            if (visited[i] == 0) {
                out.push_back(nums[i]);
                visited[i] = 1;
                dfs(nums, visited, out, res);
                visited[i] = 0;
                out.pop_back();
            }
        }
    }
};
