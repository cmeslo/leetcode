class Solution {
public:
    int numberOfMatches(int n) {
        int ans = 0;
        while (n > 0) {
            ans += n / 2;
            n -= n / 2;
            if (n == 1) break;
        }
        return ans;
    }
};
