class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        
        vector<int> dp(n);
        dp[0] = 0;
        int bCount = s[0] == 'b';
        for (int i = 1; i < n; ++i) {
            if (s[i] == 'a') {
                // keep 'a' => bCount
                // delete 'a' => dp[i - 1] + 1
                dp[i] = min(bCount, dp[i - 1] + 1);
            } else {
                dp[i] = dp[i - 1];
                bCount++;
            }
        }
        return dp.back();
    }
};

// dp[i] := a...a 或者 a...ab...b 情況下的 Minimum Deletions

// aababbab
//   i
