class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        const int M = 1e9 + 7;
        
        vector<int> dp(high + 1);
        dp[0] = 1;
        int res = 0;
        for (int i = 1; i <= high; ++i) {
            if (i >= zero)
                dp[i] = (dp[i] + dp[i - zero]) % M;
            if (i >= one)
                dp[i] = (dp[i] + dp[i - one]) % M;
            if (i >= low)
                res = (res + dp[i]) % M;
        }
        return res;
    }
};


// x x x
//     1

// 00 01 10 11
