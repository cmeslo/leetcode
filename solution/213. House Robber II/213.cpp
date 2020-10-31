class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n <= 3)
            return *max_element(begin(nums), end(nums));
        else
            return max(rob(nums, 0, n - 1), rob(nums, 1, n));
    }
    
private:
    int rob(vector<int>& nums, int start, int end) {
        int pre = nums[start];
        int last = max(pre, nums[start + 1]);
        
        int ans = 0;
        for (int i = start + 2; i < end; ++i) {
            ans = max(pre + nums[i], last);
            pre = last;
            last = ans;
        }
        
        return ans;
    }
};
