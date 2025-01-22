class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        dfs(nums, 0, 0, ans);
        return ans;
    }
    
private:
    void dfs(vector<int>& nums, int s, int cur, int& ans) {
        ans += cur;
        for (int i = s; i < nums.size(); ++i)
            dfs(nums, i + 1, cur ^ nums[i], ans);
    }
};
