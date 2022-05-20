class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int max_len = 0;
        int index = 0;
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }
            if (dp[i] > max_len) {
                index = i;
                max_len = dp[i];
            }
        }
        
        vector<int> res;
        while (index != -1) {
            res.push_back(nums[index]);
            index = prev[index];
        }
        return res;
    }
};
