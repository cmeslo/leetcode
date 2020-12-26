class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(begin(nums), end(nums), 0);
        if (sum & 1) return false;
        
        mem.clear();
        mem.resize(nums.size(), vector<int>(sum / 2 + 1, -1));
        
        return subsetSum(nums, 0, sum / 2);
    }
    
private:
    vector<vector<int>> mem;
    
    bool subsetSum(vector<int>& nums, int i, int remain) {
        if (remain == 0) return true;
        if (i >= nums.size() || remain < 0) return false;
        if (mem[i][remain] != -1) return mem[i][remain];
        
        return mem[i][remain] = subsetSum(nums, i + 1, remain - nums[i])
            || subsetSum(nums, i + 1, remain);
    }
};
