class Solution {
public:
    int countArrangement(int N) {
        vector<int> nums(N);
        for (int i = 0; i < N; ++i) nums[i] = i + 1;
        return helper(N, 0, nums);
    }
    
    int helper(int n, int pos, vector<int>& nums) {
        if (pos == n) return 1;
        
        int res = 0;
        for (int i = pos; i < n; ++i) {
            if ((pos + 1) % nums[i] == 0 || nums[i] % (pos + 1) == 0) {
                swap(nums[i], nums[pos]);
                res += helper(n, pos + 1, nums);
                swap(nums[i], nums[pos]);
            }
        }
        return res;
    }
};
