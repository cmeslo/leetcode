class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k || n < k) return false;
        int target = sum / k;
        
        sort(nums.rbegin(), nums.rend());
        for (int x : nums)
            if (x > target) return false;
        
        vector<bool> visited(n);
        return dfs(nums, k, 0, 0, target, visited);
    }
    
private:
    bool dfs(vector<int>& nums, int k, int cur, int sum, int target, vector<bool>& visited) {
        if (k == 0) return true;
        if (sum > target) return false;
        if (sum == target)
            return dfs(nums, k - 1, 0, 0, target, visited);
        
        int pre = -1;
        for (int i = cur; i < nums.size(); ++i) {
            if (visited[i]) continue;
            if (nums[i] == pre) continue;
            pre = nums[i];
            visited[i] = true;
            if (dfs(nums, k, i + 1, sum + nums[i], target, visited))
                return true;
            visited[i] = false;
        }
        return false;
    }
};
