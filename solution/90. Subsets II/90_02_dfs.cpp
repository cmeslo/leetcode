class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        visited.resize(n);
        
        sort(nums.begin(), nums.end());
        
        vector<int> cur;
        dfs(nums, 0, cur);
        return res;
    }

private:
    vector<vector<int>> res;
    vector<bool> visited;
    
    void dfs(vector<int>& nums, int start, vector<int>& cur) {
        res.push_back(cur);
        
        for (int i = start; i < nums.size(); ++i) {
            if (i > start && nums[i - 1] == nums[i]) continue;
            visited[i] = true;
            cur.push_back(nums[i]);
            dfs(nums, i + 1, cur);
            cur.pop_back();
            visited[i] = false;
        }
    }
};
