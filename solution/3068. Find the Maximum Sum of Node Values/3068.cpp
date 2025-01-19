class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        const int n = nums.size();
        vector<int> diff(n);
        for (int i = 0; i < n; ++i) {
            diff[i] = (nums[i] ^ k) - nums[i];
        }
        sort(diff.rbegin(), diff.rend());
        
        long long max_diff = 0;
        for (int i = 0; i + 1 < n; i += 2) {
            int d = diff[i] + diff[i + 1];
            if (d <= 0) break;
            max_diff += d;
        }
        
        return max_diff + accumulate(nums.begin(), nums.end(), 0LL);
    }
};
