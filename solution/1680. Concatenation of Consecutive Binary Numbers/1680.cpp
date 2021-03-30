class Solution {
public:
    int concatenatedBinary(int n) {
        const int k = 1e9 + 7;
        
        long ans = 0;
        for (int i = 1, len = 0; i <= n; ++i) {
            if ((i & (i - 1)) == 0) ++len;
            ans = ((ans << len) % k + i) % k;
        }
        return ans;
    }
};
