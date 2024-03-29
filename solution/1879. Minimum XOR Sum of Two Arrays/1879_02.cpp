class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        vector<int> dp(1 << m, INT_MAX / 2);
        vector<int> dp2;
        dp[0] = 0;
        for (int j = 0; j < m; ++j) {
            dp2 = dp;
            int k = j + 1;
            int state = (1 << k) - 1;            
            while (state < (1 << m))
            {
                for (int i = 0; i < m; ++i) {
                    if ((state >> i) & 1) {
                        dp[state] = min(dp[state], dp2[state - (1 << i)] + (nums1[i] ^ nums2[j]));
                    }
                }

                int c = state & - state;
                int r = state + c;
                state = (((r ^ state) >> 2) / c) | r;
            }
        }
        return dp[(1 << m) - 1];
    }
};
