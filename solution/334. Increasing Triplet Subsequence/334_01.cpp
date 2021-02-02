class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> mins(n), maxs(n);
        
        mins[0] = nums[0];
        for (int i = 1; i < n; ++i)
            mins[i] = min(mins[i - 1], nums[i]);
        
        maxs[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i)
            maxs[i] = max(nums[i], maxs[i + 1]);
        
        for (int i = 1; i < n - 1; ++i)
            if (mins[i] < nums[i] && nums[i] < maxs[i])
                return true;
        
        return false;
    }
};
