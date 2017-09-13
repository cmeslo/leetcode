class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        vector<int> root;
        dfs(nums, 0, root, res);
        return res;
    }
    
    void dfs(vector<int>& nums, int index, vector<int>& root, vector<vector<int>>& res) {
        res.push_back(root);
        for (int i = index; i < nums.size(); ++i) {
            root.push_back(nums[i]);
            dfs(nums, i + 1, root, res);
            root.pop_back();
            while(nums[i] == nums[i + 1]) ++i;
        }
    }
};
