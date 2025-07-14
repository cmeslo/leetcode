class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        s = '#' + s;
        int dpi = 0, bCount = 0;
        for (int i = 1; i <= n; ++i) {
            if (s[i] == 'a') {
                // keep 'a' => bCount
                // delete 'a' => dp[i - 1] + 1
                // dp[i] = min(bCount, dp[i - 1] + 1);
                dpi = min(bCount, dpi + 1);
            } else {
                // dp[i] = dp[i - 1];
                bCount++;
            }
        }
        return dpi;
    }
};

// dp[i] := a...a 或者 a...ab...b 情況下的 Minimum Deletions

// aababbab
//   i
