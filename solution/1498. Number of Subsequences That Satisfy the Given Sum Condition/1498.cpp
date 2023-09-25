class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int M = 1e9 + 7;
        int n = nums.size();
        vector<long> power(n + 1, 1);
        for (int i = 1; i <= n; ++i)
            power[i] = power[i - 1] * 2 % M;
        
        long ans = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0, j = n - 1; i <= j; ++i) {
            while (i <= j && nums[i] + nums[j] > target)
                j--;
            if (j < i) break;
            ans = (ans + power[j - i]) % M;
        }
        return ans;
    }
};
