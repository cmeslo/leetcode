class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(begin(nums), 1);
        nums.push_back(1);
        
        vector<vector<int>> mem(n + 1, vector<int>(n + 1, -1));
        return dp(nums, 1, n, mem);
    }
    
private:
    int dp(vector<int>& nums, int l, int r, vector<vector<int>>& mem) {
        if (l > r) return 0;
        if (mem[l][r] != -1) return mem[l][r];
        if (l == r) return mem[l][r] = nums[l - 1] * nums[l] * nums[l + 1];
        for (int i = l; i <= r; ++i) {
            int sum = nums[l - 1] * nums[i] * nums[r + 1] + dp(nums, l, i - 1, mem) + dp(nums, i + 1, r, mem);
            mem[l][r] = max(mem[l][r], sum);
        }
        return mem[l][r];
    }
};
