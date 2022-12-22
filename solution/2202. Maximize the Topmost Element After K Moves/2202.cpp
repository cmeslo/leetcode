class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 1 && k % 2 == 1) return -1;
        
        int mx = 0;
        // case1: remove k - 1, add one pile back
        int len = min(n, k - 1);
        for (int i = 0; i < len; ++i)
            mx = max(mx, nums[i]);
        
        // case2: remove all
        if (n > k)
            mx = max(mx, nums[k]);
        
        return mx;
    }
};
