class Solution {
public:
    int findIntegers(int n) {
        vector<int> dp(32); // dp[m]: 在長度為m位二進制序列中，當中有多少個、不包含連續的1
        dp[0] = 1; // 沒有任何位數，也代表不包含連續的1，所以代表1位
        dp[1] = 2; // 1位，可以是 0 或者 1
        for (int i = 2; i < 32; ++i)
            dp[i] = dp[i - 1] + dp[i - 2];
        
        int ans = 0;
        int pre_bit = 0, i = 30; // i=31 或者 i=30 都可以，因為第32位是符號位，這題裡只會是0（正整數）
        while (i >= 0) {
            if (n & (1 << i)) {
                ans += dp[i];
                if (pre_bit) return ans;
                pre_bit = 1;
            } else {
                pre_bit = 0;
            }
            i--;
        }
        return ans + 1; // 可以走到尾，代表 n 也是符合的
    }
};

// 1010101011
// 0000000000
//  111111111
