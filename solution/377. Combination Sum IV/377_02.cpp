class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        mem_.resize(target + 1, -1);
        mem_[0] = 1;
        return dp(nums, target);
    }
    
private:
    vector<int> mem_;
    
    int dp(vector<int>& nums, int target) {
        if (target < 0) return 0;
        if (mem_[target] != -1) return mem_[target];
        
        int ans = 0;
        for (int x : nums)
            ans += dp(nums, target - x);
        return mem_[target] = ans;
    }
};
