class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int ans = 0;
        unordered_map<int, int> dp;
        
        for (int n : arr) {
            if (dp.count(n - difference))
                dp[n] = dp[n - difference] + 1;
            else
                dp[n] = 1;
            
            ans = max(ans, dp[n]);
        }
        
        return ans;
    }
};
